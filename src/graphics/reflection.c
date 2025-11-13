/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:35:22 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/13 16:06:25 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	compute_reflection(t_ray *r, t_scene *s, t_hit *hitten, int depth)
{
	t_vec	reflect_dir;
	t_vec	hit_point_offset;
	t_ray	reflect_ray;

	reflect_dir = vec_sub(r->dir, vec_scal(hitten->normal, 2 * \
		vec_dot(r->dir, hitten->normal)));
	reflect_dir = vec_norm(reflect_dir);
	hit_point_offset = vec_sum(hitten->point, \
		vec_scal(hitten->normal, EPSILON));
	reflect_ray = (t_ray){hit_point_offset, reflect_dir};
	return (ray_color(&reflect_ray, s, depth + 1));
}
