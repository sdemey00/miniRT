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

t_obj	*get_closest_hit(const t_ray *r, float *closest_t, t_scene *s)
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

// static void apply_gamma(t_color *color, float gamma)
// {
//     color->x = ft_pow(color->x / 255.0, 1.0 / gamma) * 255.0;
//     color->y = ft_pow(color->y / 255.0, 1.0 / gamma) * 255.0;
//     color->z = ft_pow(color->z / 255.0, 1.0 / gamma) * 255.0;
// }

t_color	ray_color(t_ray *r, t_scene *s, int depth)
{
	t_obj	*hit_obj;
	float	closest_t;
	t_color	color;
	t_color	reflected_color;
	//float	attenuation;

	if (depth > 3)
		return ((t_color){0, 0, 0});
	closest_t = INFINITY;
	hit_obj = get_closest_hit(r, &closest_t, s);
	if (!hit_obj)
		return (s->bg);
	color = ray_light_color(s, r, hit_obj, closest_t);
	// attenuation = 1.0 / (1.0 + 0.09 * closest_t + 0.032 * closest_t * closest_t);
	// color = vec_scal(color, attenuation);
	// color = vec_scal(color, 1.7);
	if (hit_obj->reflection) // hit_obj.reflection
	{
		reflected_color = compute_reflection(r, s, closest_t, hit_obj, depth);
		color = vec_sum(
				vec_scal(color, 1 - hit_obj->reflection), // hit_obj.reflection
				vec_scal(reflected_color, hit_obj->reflection) //same
				);
	}
	//apply_gamma(&color, 1.7);
	//vec_print(&color);
	vec_fmin((t_vec *)&color, 255.0);
	return (color);
}
