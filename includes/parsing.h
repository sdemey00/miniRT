#ifndef PARSING_H
# define PARSING_H

#include "minirt.h"

int		parse_file(char *filename, t_scene *scene);
void	parse_line(char *line, t_scene *scene);

void	parse_ambiant(char **split, t_scene *scene);
void	parse_camera(char **split, t_scene *scene);
void	parse_light(char **split, t_scene *scene);
void	parse_sphere(char **split, t_scene *scene);
void	parse_plane(char **split, t_scene *scene);
void	parse_cylinder(char **split, t_scene *scene);

// UTILS
t_vec	parse_vec(char *str);
t_color	parse_color(char *str);
void	check_range_double(double val, double min, double max, char *msg);
void	check_range_int(int val, int min, int max, char *msg);
double	ft_atof(const char *str);
void	ft_free_split(char **tab);
// PRINT
void	print_scene_infos(t_scene *scene);
void	print_ambiant_infos(t_scene *scene);
void	print_camera_infos(t_scene *scene);
void	print_light_infos(t_scene *scene);
void	print_spheres_infos(t_scene *scene);
void	print_planes_infos(t_scene *scene);
void	print_cylinders_infos(t_scene *scene);
//void	normalize_vec(t_vec *v);


#endif
