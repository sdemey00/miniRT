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

t_color ray_color(t_ray *r, t_scene *s)
{
	t_idx	i;

	i = 0;
	while (i < s->objs_len)
	{
		if ((s->objs[i].e_type == SPHERE && ray_hit_sphere(r, &s->objs[i])) || \
			(s->objs[i].e_type == PLANE && ray_hit_plane(r, &s->objs[i])) || \
			(s->objs[i].e_type == CYLINDER && ray_hit_cylinder(r, &s->objs[i])))
			return (s->objs[i].color);
		i++;
	}
    return (t_color){135,206,235};
}
