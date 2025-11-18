/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 16:50:17 by sdemey            #+#    #+#             */
/*   Updated: 2025/11/18 13:24:49 by mmichele         ###   ########.fr       */
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

static void	map_plane(float *u, float *v, t_vec local)
{
	*u = local.x * 0.2;
	*v = local.z * 0.2;
}

static void	map_cylinder(float *u, float *v, t_vec local, t_obj *obj)
{
	float	theta;

	theta = atan2(local.z, local.x);
	*u = (theta + FT_PI) / (2.0 * FT_PI);
	*v = fmodf(local.y / obj->height, 1.0);
	if (*v < 0.0)
		*v += 1.0;
}

static void	map_cone(float *u, float *v, t_vec local)
{
	*u = atan2(local.x, local.z) / (2.0 * FT_PI);
	if (*u < 0.0)
		*u += 1.0;
	*v = fmodf(local.y * 0.001, 1.0);
	if (*v < 0)
		*v += 1.0;
}

static t_vec	get_local_hit(t_hit *hitten, t_vec local_hit)
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

t_vec	map_obj(t_hit *hitten)
{
	t_vec	local_hit;
	t_vec	local;
	float	u;
	float	v;


	local_hit = vec_sub(hitten->point, hitten->obj->pos);
	local = get_local_hit(hitten, local_hit);
	u = 0.0;
	v = 0.0;
	if (hitten->obj->e_type == SPH)
		map_sphere(&u, &v, local_hit);
	else if (hitten->obj->e_type == PLA || hitten->obj->e_type == CIR)
		map_plane(&u, &v, local);
	else if (hitten->obj->e_type == CYL)
		map_cylinder(&u, &v, local, hitten->obj);
	else if (hitten->obj->e_type == CON)
		map_cone(&u, &v, local);
	return ((t_vec){u, v, 0});
}
