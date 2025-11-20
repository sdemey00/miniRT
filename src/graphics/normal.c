/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_surface_normal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemey <sdemey@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:34:52 by sdemey            #+#    #+#             */
/*   Updated: 2025/11/18 18:28:47 by sdemey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	compute_tangent_space(t_hit *h)
{
	t_vec	up;
	t_vec	axis;

	up = (t_vec){0, 1, 0};
	if (ft_abs(h->normal.y) > 0.999)
		up = (t_vec){1, 0, 0};
	if (h->obj->e_type == SPH)
	{
		h->tangent = vec_norm((t_vec){-h->normal.z, 0.0, h->normal.x});
		if (vec_mag(h->tangent) < EPSILON)
			h->tangent = vec_norm(vec_cross(up, h->normal));
	}
	else if (h->obj->e_type == PLA || h->obj->e_type == CIR)
		h->tangent = vec_norm(vec_cross(up, h->obj->dir));
	else if (h->obj->e_type == CYL)
	{
		axis = h->obj->dir;
		h->tangent = vec_norm(vec_cross(axis, h->normal));
		if (vec_mag(h->tangent) < EPSILON)
			h->tangent = vec_norm(vec_cross(up, h->normal));
	}
	h->bitangent = vec_cross(h->normal, h->tangent);
	h->tangent = vec_norm(h->tangent);
	h->bitangent = vec_norm(h->bitangent);
}

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
