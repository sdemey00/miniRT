/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemey <sdemey@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 16:50:17 by sdemey            #+#    #+#             */
/*   Updated: 2025/11/15 16:50:19 by sdemey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	map_sphere(float *u, float *v, t_vec hit_point)
{
	t_vec	p;
	float	theta;
	float	phi;

	p = vec_norm(hit_point);
	theta = atan2(p.z, p.x);
	phi = acos(p.y);
	*u = (theta + FT_PI) / (2.0 * FT_PI);
	*v = phi / FT_PI;
}

static void	map_plane(float *u, float *v, t_vec hit_point, t_obj *obj)
{
	t_vec	tmp_up;
	t_vec	right;
	t_vec	up;

	tmp_up = (t_vec){0, 1, 0};
	if (ft_abs(obj->dir.y) > 0.999)
		tmp_up = (t_vec){1, 0, 0};
	right = vec_norm(vec_cross(tmp_up, obj->dir));
	up = vec_cross(obj->dir, right);
	*u = vec_dot(hit_point, right) * 0.2;
	*v = vec_dot(hit_point, up) * 0.2;
}

static void	map_cylinder(float *u, float *v, t_vec hit_point, t_obj *obj)
{
	float	theta;
	t_vec	tmp_up;
	t_vec	right;
	t_vec	up;
	t_vec	local;

	tmp_up = (t_vec){0, 1, 0};
	if (ft_abs(obj->dir.y) > 0.999)
		tmp_up = (t_vec){1, 0, 0};
	right = vec_norm(vec_cross(tmp_up, obj->dir));
	up = vec_cross(obj->dir, right);
	local = (t_vec){vec_dot(hit_point, right), vec_dot(hit_point, obj->dir), vec_dot(hit_point, up)};
	theta = atan2(local.z, local.x);
	*u = (theta + FT_PI) / (2.0 * FT_PI);
	*v = fmodf(local.y / obj->height, 1.0);
	if (*v < 0.0)
		*v += 1.0;
}

static void	map_cone(float *u, float *v, t_vec hit_point, t_obj *obj)
{
	t_vec	tmp_up;
	t_vec	right;
	t_vec	up;
	t_vec	local;

	tmp_up = (t_vec){0, 1, 0};
	if (ft_abs(obj->dir.y) > 0.999)
		tmp_up = (t_vec){1, 0, 0};
	right = vec_norm(vec_cross(tmp_up, obj->dir));
	up = vec_cross(obj->dir, right);
	local = (t_vec){vec_dot(hit_point, right), vec_dot(hit_point, obj->dir), vec_dot(hit_point, up)};
	*u = atan2(local.z, local.x) / (2.0 * FT_PI);
	if (*u < 0.0)
		*u += 1.0;
	*v = local.y * 0.2;
}

t_vec	map_obj(t_hit *hitten)
{
	t_vec	local_hit;
	float	u;
	float	v;

	u = 0.0;
	v = 0.0;
	local_hit = vec_sub(hitten->point, hitten->obj->pos);
	if (hitten->obj->e_type == SPH)
		map_sphere(&u, &v, local_hit);
	else if (hitten->obj->e_type == PLA || hitten->obj->e_type == CIR)
		map_plane(&u, &v, local_hit, hitten->obj);
	else if (hitten->obj->e_type == CYL)
		map_cylinder(&u, &v, local_hit, hitten->obj);
	else if (hitten->obj->e_type == CON)
		map_cone(&u, &v, local_hit, hitten->obj);
	return ((t_vec){u, v, 0});
}
