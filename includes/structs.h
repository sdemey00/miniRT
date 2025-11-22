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
	t_vec		pos;		// Position
	t_vec		dir;		// Normalized direction vector
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
	CHECKER_PATTERN = 4,
	TEXTURE = 5,
	BUMP = 6
};

typedef struct s_tex
{
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
	int		w;
	int		h;
	char	path[1024];
	t_bool	loaded;
}	t_tex;

typedef struct s_bump
{
	enum
	{
		NO_BUMP,
		PROC_WAVE,
		PROC_NOISE,
		XPM_TEX,
		XPM_BUMP
	}		e_type;
	t_tex	texture;
}	t_bump;

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
	float		reflexion;
	t_bitmap	effects;
	t_tex		texture;
	t_bump		bump;
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

/* Structure with useful informations on ray closest hit point */
typedef struct s_hit
{
	t_obj	*obj;
	float	dist;
	t_vec	point;
	t_vec	normal;
	t_vec	uv;
	t_vec	p_offset;
	t_vec	tangent;
	t_vec	bitangent;
}	t_hit;

/* Structure with 2nd degree equation roots variables */
typedef struct s_eq2
{
	float	a;
	float	b;
	float	c;
	float	d;
	float	t[2];
}	t_eq2;

/* MLX pixel grid manipulation */
typedef struct s_image
{
	void	*ptr;
	char	*address;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_image;

/* Graphical library context -> MLX */
typedef struct s_window
{
	void	*mlx;
	void	*win;
	t_image	img;
	int		fd_controller;
}	t_window;

/* Context render state */
enum	e_rstate
{
	NONE,
	RENDERING,
	RENDERED
};

/* Input method */
enum	e_input_method
{
	CONTROLLER,
	KBM
};

struct s_ctx
{
	t_window			w;
	t_scene				s;
	enum e_rstate		state;
	enum e_input_method	input;
};

#endif // STRUCTS_H
