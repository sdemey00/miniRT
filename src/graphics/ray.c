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
			if (t < *closest_t)
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
	if (bitmap_get(&s->effects, CHECKER_PATTERN)
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
	hitten = get_closest_hit(r, s);
	if (!hitten.obj)
		return (s->bg);
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
	color = vec_fmin((t_vec *)&color, 1.0);
	return (color);
}
