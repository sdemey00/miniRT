/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemey <sdemey@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:38:33 by sdemey            #+#    #+#             */
/*   Updated: 2025/11/01 17:29:58 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_ray
{
	t_vec	origin;
	t_vec	dir;
}	t_ray;

typedef t_vec	t_color;

typedef struct s_ambiant
{
	float	ratio;
	t_color	color;
	t_bool	set;
}	t_ambiant;

typedef struct s_camera
{
	t_vec		pos;
	t_vec		dir;
	t_ssuint	fov;
	t_bool		set;
}	t_camera;

typedef struct s_light
{
	t_vec	pos;
	float	brightness;
	t_color	color;
}	t_light;

typedef struct s_sphere
{
	t_vec	center;
	float	diameter;
	t_color	color;
}	t_sphere;

typedef struct s_plane
{
	t_vec	point;
	t_vec	normal;
	t_color	color;
}	t_plane;

typedef struct s_cylinder
{
	t_vec	center;
	t_vec	axis;
	float	diameter;
	float	height;
	t_color	color;
}	t_cylinder;

typedef struct s_scene
{
	t_ambiant	ambiant;
	t_camera	camera;
	t_light		lights[128];
	t_ssuint	lights_idx;
	t_sphere	spheres[128];
	t_ssuint	spheres_idx;
	t_plane		planes[128];
	t_ssuint	planes_idx;
	t_cylinder	cylinders[128];
	t_ssuint	cylinders_idx;
}	t_scene;

#endif // STRUCTS_H
