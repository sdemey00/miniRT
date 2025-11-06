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
	float	intensity;
	t_color	color;
	t_bool	set;
}	t_ambiant;

typedef struct s_camera
{
	t_vec		pos;
	t_vec		dir;
	t_ssuint	fov;
	t_vec		forward;
	t_vec		world_up;
	t_vec		right;
	t_vec		up;
	t_bool		set;
}	t_camera;

typedef struct s_light
{
	t_vec	pos;
	float	intensity;
	t_color	color;
}	t_light;

typedef struct s_obj
{
	enum
	{
		SPHERE,
		PLANE,
		CYLINDER
	}	e_type;
	t_vec	pos;
	t_vec	dir;
	t_color	color;
	float	radius;
	float	height;
}	t_obj;

typedef struct s_scene
{
	t_ambiant	ambiant;
	t_camera	camera;
	t_light		lights[128];
	t_ssuint	lights_len;
	t_obj		objs[128];
	t_ssuint	objs_len;
}	t_scene;

#endif // STRUCTS_H
