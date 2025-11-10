/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemey <sdemey@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:38:33 by sdemey            #+#    #+#             */
/*   Updated: 2025/11/06 18:43:17 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define SPACE_UP (t_vec){0, 1, 0}

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
	t_bool		set;
	float		ratio;		// Screen ratio
	float		flen;		// Focal length
	t_vec		up;			// Camera up direction
	t_vec		right;		// Camera right direction
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
		SPH,
		PLA,
		CYL,
		CON
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

typedef struct s_eq2
{
	float	a;
	float	b;
	float	c;
	float	d;
	float	t[2];
}	t_eq2;

#endif // STRUCTS_H
