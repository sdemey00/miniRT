/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkboard_pattern.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:35:03 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/13 10:30:06 by mmichele         ###   ########.fr       */
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

	theta = atan2(hit_point.z, hit_point.x);
	*u = (theta + FT_PI) / (2.0 * FT_PI);
	*v = fmodf(hit_point.y / obj->height, 1.0);
	if (*v < 0)
		*v += 1.0;
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
	else if (hitten->obj->e_type == PLA)
		map_plane(&u, &v, local_hit, hitten->obj);
	else if (hitten->obj->e_type == CYL)
		map_cylinder(&u, &v, local_hit, hitten->obj);
	return ((t_vec){u, v, 0});
}

t_color	checkboard_pattern(t_hit *hitten)
{
	float	scale;

	scale = 30.0;
	if (hitten->obj->e_type == PLA)
		scale = 5.0;
	if (((int)floor(hitten->uv.x * scale)
			+ (int)floor(hitten->uv.y * scale)) % 2 == 0)
		return (hitten->obj->color);
	return ((t_color){255, 255, 255});
}
