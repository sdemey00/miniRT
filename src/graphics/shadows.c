/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:35:16 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/13 16:03:07 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	is_in_shadow(t_scene *s, t_vec hit_point, t_vec normal, t_light light)
{
	t_vec	light_dir;
	t_vec	hit_point_offset;
	t_ray	shadow_ray;
	t_obj	*shadow_obj;

	light_dir = vec_norm(vec_sub(light.pos, hit_point));
	hit_point_offset = vec_sum(hit_point, vec_scal(normal, EPSILON));
	shadow_ray = (t_ray){hit_point_offset, light_dir};
	shadow_obj = get_closest_hit(&shadow_ray, s).obj;
	if (!shadow_obj)
		return (0);
	return (1);
}
