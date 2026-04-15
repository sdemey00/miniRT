/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:06:21 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/05 17:06:30 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static float	clampf(const float v, const float lo, const float hi)
{
	if (v < lo)
		return (lo);
	if (v > hi)
		return (hi);
	return (v);
}

static t_color	color_lerp(const t_color a, const t_color b, const float t)
{
	const float	u = clampf(t, 0.0f, 1.0f);

	return ((t_color){
		a.x + (b.x - a.x) * u,
		a.y + (b.y - a.y) * u,
		a.z + (b.z - a.z) * u
	});
}

static t_bool	find_blackhole_and_disk(t_scene *s, t_obj **bh, t_obj **disk)
{
	t_idx	i;
	t_idx	j;
	float	best_dist;
	float	d;

	*bh = NULL;
	*disk = NULL;
	best_dist = INFINITY;
	i = 0;
	while (i < s->objs_len)
	{
		if (s->objs[i].e_type == SPH && s->objs[i].radius > EPSILON
			&& (s->objs[i].color.x + s->objs[i].color.y + s->objs[i].color.z) <= 5)
		{
			j = 0;
			while (j < s->objs_len)
			{
				if (s->objs[j].e_type == CIR && s->objs[j].radius > s->objs[i].radius && \
					s->objs[i].pos.x == s->objs[j].pos.x && s->objs[i].pos.y == s->objs[j].pos.y && \
					s->objs[i].pos.z == s->objs[j].pos.z)
				{
					d = vec_mag(vec_sub(s->objs[j].pos, s->objs[i].pos));
					if (d < best_dist)
					{
						best_dist = d;
						*bh = &s->objs[i];
						*disk = &s->objs[j];
					}
				}
				j++;
			}
		}
		i++;
	}
	return (*bh && *disk);
}

static t_bool	segment_disk_crossing(const t_vec p0, const t_vec p1,
		const t_obj *bh, const t_obj *disk, t_vec *x)
{
	const t_vec	seg = vec_sub(p1, p0);
	const float	num = vec_dot(vec_sub(bh->pos, p0), disk->dir);
	const float	den = vec_dot(seg, disk->dir);
	float		t;
	float		rho;
	t_vec		r;

	if (fabsf(den) < 1e-6f)
		return (0);
	t = num / den;
	if (t < 0.0f || t > 1.0f)
		return (0);
	*x = vec_sum(p0, vec_scal(seg, t));
	r = vec_sub(*x, bh->pos);
	r = vec_sub(r, vec_scal(disk->dir, vec_dot(r, disk->dir)));
	rho = vec_mag(r);
	if (rho < bh->radius * 1.2f || rho > disk->radius)
		return (0);
	return (1);
}

static t_color	disk_emission_color(const t_obj *bh, const t_obj *disk,
		const t_vec x, const t_vec ray_dir)
{
	const float	rin = bh->radius * 1.2f;
	const float	rout = disk->radius;
	t_vec		r;
	t_vec		rdir;
	t_vec		vdir;
	float		u;
	float		beta;
	float		mu;
	float		doppler;
	float		gamma;
	float		boost;

	r = vec_sub(x, bh->pos);
	r = vec_sub(r, vec_scal(disk->dir, vec_dot(r, disk->dir)));
	rdir = vec_norm(r);
	vdir = vec_norm(vec_cross(disk->dir, rdir));
	u = (vec_mag(r) - rin) / fmaxf(rout - rin, 1e-4f);
	u = clampf(u, 0.0f, 1.0f);
	beta = 0.65f * sqrtf(clampf(rin / fmaxf(vec_mag(r), rin), 0.0f, 1.0f));
	beta = clampf(beta, 0.0f, 0.7f);
	mu = vec_dot(vdir, vec_scal(ray_dir, -1.0f));
	gamma = 1.0f / sqrtf(fmaxf(1.0f - beta * beta, 1e-4f));
	doppler = 1.0f / (gamma * fmaxf(1.0f - beta * mu, 0.15f));
	boost = ft_pow(fmaxf(doppler, 0.0f), 3);
	return (vec_fmin(&(t_color){
		color_lerp((t_color){1.3f, 1.1f, 0.9f}, (t_color){1.0f, 0.4f, 0.12f}, u)
			.x * fminf(4.0f, boost * (1.3f / (0.2f + u * u))),
		color_lerp((t_color){1.3f, 1.1f, 0.9f}, (t_color){1.0f, 0.4f, 0.12f}, u)
			.y * fminf(4.0f, boost * (1.3f / (0.2f + u * u))),
		color_lerp((t_color){1.3f, 1.1f, 0.9f}, (t_color){1.0f, 0.4f, 0.12f}, u)
			.z * fminf(4.0f, boost * (1.3f / (0.2f + u * u)))
	}, 1.0f));
}

static t_bool	trace_blackhole_disk(t_ray *r, t_scene *s, t_color *out)
{
	t_obj	*bh;
	t_obj	*disk;
	t_vec	p;
	t_vec	d;
	t_vec	prev;
	t_vec	x;
	t_vec	rvec;
	float	dist;
	float	ds;
	float	k;
	t_idx	i;

	if (!find_blackhole_and_disk(s, &bh, &disk))
		return (0);
	p = r->origin;
	d = vec_norm(r->dir);
	ds = fmaxf(bh->radius * 0.12f, 0.03f);
	k = 0.55f * bh->radius * bh->radius;
	i = 0;
	while (i++ < 700)
	{
		rvec = vec_sub(p, bh->pos);
		dist = vec_mag(rvec);
		if (dist < bh->radius)
			return (*out = (t_color){0, 0, 0}, 1);
		prev = p;
		p = vec_sum(p, vec_scal(d, ds));
		if (segment_disk_crossing(prev, p, bh, disk, &x))
			return (*out = disk_emission_color(bh, disk, x, d), 1);
		d = vec_norm(vec_sum(d, vec_scal(rvec,
				(-k * ds) / (dist * dist * dist + 1e-4f))));
		if (dist > fmaxf(1500.0f, disk->radius * 18.0f))
			break ;
	}
	r->origin = p;
	r->dir = d;
	return (0);
}

static t_obj	*get_closest_hit_obj(const t_ray *r, float *closest_t, \
	t_scene *s)
{
	t_obj	*hit_obj;
	t_idx	i;
	float	t;

	hit_obj = NULL;
	i = 0;
	while (i < s->objs_len)
	{
		if ((s->objs[i].e_type == SPH && ray_hit_sph(r, &s->objs[i], &t)) || \
			(s->objs[i].e_type == PLA && ray_hit_pla(r, &s->objs[i], &t)) || \
			(s->objs[i].e_type == CYL && ray_hit_cyl(r, &s->objs[i], &t)) || \
			(s->objs[i].e_type == CON && ray_hit_con(r, &s->objs[i], &t)) || \
			(s->objs[i].e_type == CIR && ray_hit_cir(r, &s->objs[i], &t)))
		{
			if (EPSILON < t && t < *closest_t)
			{
				*closest_t = t;
				hit_obj = &s->objs[i];
			}
		}
		i++;
	}
	return (hit_obj);
}

t_hit	get_closest_hit(const t_ray *r, t_scene *s)
{
	t_hit	res;
	float	closest_t;

	closest_t = INFINITY;
	res.obj = get_closest_hit_obj(r, &closest_t, s);
	if (!res.obj)
		return (res);
	res.dist = closest_t;
	res.point = vec_sum(r->origin, vec_scal(r->dir, res.dist));
	res.normal = get_surface_normal(res.obj, res.point);
	res.uv = map_obj(&res);
	res.p_offset = vec_sum(res.point, vec_scal(res.normal, EPSILON));
	return (res);
}

static t_color	get_obj_color(t_scene *s, t_hit *hitten)
{
	if (bitmap_get(&s->effects, TEXTURE)
		&& bitmap_get(&hitten->obj->effects, TEXTURE)
		&& hitten->obj->texture.loaded)
		return (texture_color(&hitten->obj->texture, hitten));
	else if (bitmap_get(&s->effects, CHECKER_PATTERN)
		&& bitmap_get(&hitten->obj->effects, CHECKER_PATTERN))
		return (checkboard_pattern(hitten));
	return (hitten->obj->color);
}

static t_color	color_mix(t_color *base_color, t_color *light_color)
{
	return ((t_color){
		base_color->x * light_color->x,
		base_color->y * light_color->y,
		base_color->z * light_color->z});
}

t_color	ray_color(t_ray *r, t_scene *s, int depth)
{
	t_hit	hitten;
	t_color	color;
	t_color	reflect_color;
	t_color	light_color;
	t_color	base_color;

	if (depth > 3)
		return ((t_color){0, 0, 0});
	if (trace_blackhole_disk(r, s, &color))
		return (vec_fmin((t_vec *)&color, 1.0f));
	hitten = get_closest_hit(r, s);
	if (!hitten.obj)
		return (vec_norm(s->bg));
	if (bitmap_get(&s->effects, BUMP) && bitmap_get(&hitten.obj->effects, BUMP))
		apply_bump(&hitten, 0.8);
	base_color = get_obj_color(s, &hitten);
	base_color = vec_rscal(base_color, 255.0);
	light_color = compute_lights(s, &hitten, r);
	color = color_mix(&base_color, &light_color);
	if (hitten.obj->reflexion && bitmap_get(&s->effects, REFLEXION)
		&& bitmap_get(&hitten.obj->effects, REFLEXION))
	{
		reflect_color = compute_reflexion(r, s, &hitten, depth);
		color = vec_sum(vec_scal(color, 1 - hitten.obj->reflexion),
				vec_scal(reflect_color, hitten.obj->reflexion));
	}
	return (vec_fmin((t_vec *)&color, 1.0));
}
