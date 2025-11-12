/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkboard_pattern.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:35:03 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/11 17:35:03 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	map_sphere(float *u, float *v, t_vec hit_point)
{
	t_vec p = vec_norm(hit_point);
	float theta = atan2(p.z, p.x);
	float phi = acos(p.y);
	*u = (theta + FT_PI) / (2.0 * FT_PI);
	*v = phi / FT_PI;
}

void	map_plane(float *u, float *v, t_vec hit_point, t_obj *obj)
{
	t_vec tmp_up = fabs(obj->dir.y) > 0.999 ? (t_vec){1, 0, 0} : (t_vec){0, 1, 0};
	t_vec right = vec_norm(vec_cross(tmp_up, obj->dir));
	t_vec up = vec_cross(obj->dir, right);
	*u = vec_dot(hit_point, right) * 0.2;
	*v = vec_dot(hit_point, up) * 0.2;
}

void	map_cylinder(float *u, float *v, t_vec hit_point, t_obj *obj)
{
	t_vec p = hit_point;
	float theta = atan2(p.z, p.x);
	*u = (theta + FT_PI) / (2.0 * FT_PI);
	*v = fmodf(p.y / obj->height, 1.0f);
	if (*v < 0)
		*v += 1.0f;
}

t_color	checkboard_pattern(t_obj *obj, t_vec hit_point)
{
	float	scale = (obj->e_type == SPH ? 30.0 : obj->e_type == CYL ? 20.0 : 10.0);
	float	u, v;
	t_color	color1 = obj->color;
	t_color	color2 = (t_color){255, 255, 255};

	t_vec local_hit = vec_sub(hit_point, obj->pos);
	if (obj->e_type == SPH)
		map_sphere(&u, &v, local_hit);
	else if (obj->e_type == PLA)
		map_plane(&u, &v, local_hit, obj);
	else if (obj->e_type == CYL)
		map_cylinder(&u, &v, local_hit, obj);

	if (((int)floor(u * scale) + (int)floor(v * scale)) % 2 == 0)
		return color1;
	return color2;
}
