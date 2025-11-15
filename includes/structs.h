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

typedef struct s_ray
{
	t_vec	origin;
	t_vec	dir;
}	t_ray;

typedef t_vec			t_color;
typedef unsigned char	t_bitmap;

typedef struct s_ambiant
{
	float	intensity;
	t_color	color;
	t_color	light_norm;
	t_bool	set;
}	t_ambiant;

typedef struct s_camera
{
	t_vec		pos;
	t_vec		dir;
	t_ssuint	fov;		// Field of view
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
	t_color	norm;
	t_vec	dir;
	float	ndotl;
}	t_light;

enum	e_effects_map
{
	DIFFUSE_LIGHT = 0,
	SPECULAR_LIGHT = 1,
	SHADOWS = 2,
	REFLEXION = 3,
	CHECKER_PATTERN = 4
};

typedef struct s_obj
{
	enum
	{
		SPH,
		PLA,
		CYL,
		CON,
		CIR
	}			e_type;
	t_vec		pos;
	t_vec		dir;
	t_color		color;
	float		radius;
	float		height;
	int			shininess;
	float		reflection;
	t_bitmap	effects;
}	t_obj;

typedef struct s_scene
{
	t_ambiant	ambiant;
	t_camera	camera;
	t_light		lights[MAX_OBJS];
	t_ssuint	lights_len;
	t_obj		objs[MAX_OBJS];
	t_ssuint	objs_len;
	t_obj		*controlled;
	t_ssuint	blur;
	t_color		bg;
	t_bool		bg_set;
	t_bool		reticle;
	t_bitmap	effects;
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
