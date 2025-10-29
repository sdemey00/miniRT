#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_ambiant
{
	double	ratio;
	t_color	color;
	int		set;
}	t_ambiant;

typedef struct s_camera
{
	t_vec	pos;
	t_vec	dir;
	double	fov;
	int		set;
}	t_camera;

typedef struct s_light
{
	t_vec	pos;
	double	brightness;
	t_color	color;
	int		set;
}	t_light;

typedef struct s_sphere
{
	t_vec				center;
	double				diameter;
	t_color				color;
}	t_sphere;

typedef struct s_plane
{
	t_vec				point;
	t_vec				normal;
	t_color				color;
}	t_plane;

typedef struct s_cylinder
{
	t_vec				center;
	t_vec				axis;
	double				diameter;
	double				height;
	t_color				color;
}	t_cylinder;

typedef struct s_scene
{
	t_ambiant	ambiant;
	t_camera	camera;
	t_light		light;
	t_sphere	spheres[128];
	t_ssuint	spheres_idx;
	t_plane		planes[128];
	t_ssuint	planes_idx;
	t_cylinder	cylinders[128];
	t_ssuint	cylinders_idx;
}	t_scene;

#endif
