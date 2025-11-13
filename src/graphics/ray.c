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
	// TODO res.uv = 
	return (res);
}

// static void apply_gamma(t_color *color, float gamma)
// {
//     color->x = ft_pow(color->x / 255.0, 1.0 / gamma) * 255.0;
//     color->y = ft_pow(color->y / 255.0, 1.0 / gamma) * 255.0;
//     color->z = ft_pow(color->z / 255.0, 1.0 / gamma) * 255.0;
// }

t_color	ray_color(t_ray *r, t_scene *s, int depth)
{
	t_hit	hitten;
	t_color	color;
	t_color	reflected_color;
	t_color	light_color;
	t_color	base_color;
	//float	attenuation;

	if (depth > 3)
		return ((t_color){0, 0, 0});
	hitten = get_closest_hit(r, s);
	if (!hitten.obj)
		return (s->bg);
	light_color = compute_lights(s, &hitten, r);
	base_color = hitten.obj->color;
	if (hitten.obj->checkboard)
		base_color = checkboard_pattern(hitten.obj, hitten.point);
	color = (t_color){
		base_color.x * light_color.x,
		base_color.y * light_color.y,
		base_color.z * light_color.z};
	vec_fmin((t_vec *)&color, 255.0);
	// attenuation = 1.0 / (1.0 + 0.09 * closest_t + 0.032 * closest_t * closest_t);
	// color = vec_scal(color, attenuation);
	// color = vec_scal(color, 1.7);
	if (hitten.obj->reflection) // hitten.reflection
	{
		reflected_color = compute_reflection(r, s, &hitten, depth);
		color = vec_sum(
				vec_scal(color, 1 - hitten.obj->reflection), // hitten.reflection
				vec_scal(reflected_color, hitten.obj->reflection) //same
				);
	}
	//apply_gamma(&color, 1.7);
	//vec_print(&color);
	vec_fmin((t_vec *)&color, 255.0);
	return (color);
}
