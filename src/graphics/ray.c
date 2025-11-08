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
		if (s->objs[i].e_type == SPHERE
			&& ray_hit_sphere(r, &s->objs[i], &t))
		{
			if (t < *closest_t)
			{
				*closest_t = t;
				hit_obj = &s->objs[i];
			}
		}
		else if (s->objs[i].e_type == PLANE
			&& ray_hit_plane(r, &s->objs[i], &t))
		{
			if (t < *closest_t)
			{
				*closest_t = t;
				hit_obj = &s->objs[i];
			}
		}
		else if (s->objs[i].e_type == CYLINDER
        	&& ray_hit_cylinder(r, &s->objs[i], &t))
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

t_color	ray_color(t_ray *r, t_scene *s)
{
	t_obj	*hit_obj;
	float	closest_t;

	closest_t = INFINITY;
	hit_obj = get_closest_hit(r, &closest_t, s);
	if (!hit_obj)
		return ((t_color){135, 206, 235});
	return (ray_light_color(s, r, hit_obj, closest_t));
}
