/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_surface_normal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:34:52 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/11 17:34:53 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	get_local_hit(t_hit *hitten, t_vec local_hit)
{
	t_vec	tmp_up;
	t_vec	right;
	t_vec	up;

	tmp_up = (t_vec){0, 1, 0};
	if (ft_abs(hitten->obj->dir.y) > 0.999)
		tmp_up = (t_vec){1, 0, 0};
	right = vec_norm(vec_cross(tmp_up, hitten->obj->dir));
	up = vec_cross(hitten->obj->dir, right);
	return ((t_vec){
		vec_dot(local_hit, right),
		vec_dot(local_hit, hitten->obj->dir),
		vec_dot(local_hit, up)});
}

static t_vec	cone_normal(t_obj *obj, t_vec hit_point)
{
	t_vec	ap;
	float	h;
	t_vec	normal;

	ap = vec_sub(hit_point, obj->pos);
	h = vec_dot(ap, obj->dir);
	normal = vec_sub(ap, vec_scal(obj->dir, 2.0 * h));
	return (vec_norm(normal));
}

t_vec	get_surface_normal(t_obj *obj, t_vec hit_point)
{
	if (obj->e_type == SPH)
		return (vec_norm(vec_sub(hit_point, obj->pos)));
	else if (obj->e_type == PLA || obj->e_type == CIR)
		return (vec_norm(obj->dir));
	else if (obj->e_type == CYL)
		return (vec_norm((t_vec){
				hit_point.x - obj->pos.x, 0, hit_point.z - obj->pos.z}));
	else if (obj->e_type == CON)
		return (cone_normal(obj, hit_point));
	return ((t_vec){0, 1, 0});
}
