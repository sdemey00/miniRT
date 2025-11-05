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

t_color	ray_color(t_ray *r, t_scene *s)
{
	float closest_t = INFINITY;
	t_obj *hit_obj = NULL;
	for (t_idx i = 0; i < s->objs_len; i++)
	{
		float t;
		if (s->objs[i].e_type == SPHERE && ray_hit_sphere(r, &s->objs[i], &t))
		{
			if (t < closest_t)
			{
				closest_t = t;
				hit_obj = &s->objs[i];
			}
		}
		else if (s->objs[i].e_type == PLANE && ray_hit_plane(r, &s->objs[i], &t))
		{
			if (t < closest_t)
			{
				closest_t = t;
				hit_obj = &s->objs[i];
			}
		}
	}
	if (hit_obj)
		return (hit_obj->color);
	return ((t_color){135,206,235});
}
