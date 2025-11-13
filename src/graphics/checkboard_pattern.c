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

void	map_sphere(float *u, float *v, t_vec hit_point)
{
	float	theta;
	float	radius;
	float	phi;

	radius = vec_mag(hit_point);
	theta = atan2(hit_point.z, hit_point.x);
	phi = acos(hit_point.y / radius);
	*u = (theta + FT_PI) / (2.0 * FT_PI);
	*v = phi / FT_PI;
}

void	map_plane(float *u, float *v, t_vec hit_point)
{
	*u = hit_point.x * 0.1;
	*v = hit_point.z * 0.1;
}

void	map_cylinder(float *u, float *v, t_vec hit_point)
{
	float	theta;

	theta = atan2(hit_point.x, hit_point.z);
	*u = 1.0 - (theta / (2.0 * FT_PI) + 0.5);
	*v = hit_point.y * 0.1;
}

t_color	checkboard_pattern(t_obj *obj, t_vec hit_point)
{
	const float	scale = 15.0;
	float		u;
	float		v;
	t_color		color1;
	t_color		color2;

	u = 0;
	v = 0;
	color1 = obj->color;
	color2 = (t_color){255, 255, 255};
	if (obj->e_type == SPH)
		map_sphere(&u, &v, hit_point);
	if (obj->e_type == PLA)
		map_plane(&u, &v, hit_point);
	if (obj->e_type == CYL)
		map_cylinder(&u, &v, hit_point);
	if ((((int)floor(u * scale) + (int)floor(v * scale)) % 2) == 0)
		return (color1);
	return (color2);
}
