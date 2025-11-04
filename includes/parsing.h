/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemey <sdemey@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:38:18 by sdemey            #+#    #+#             */
/*   Updated: 2025/10/31 12:38:20 by sdemey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minirt.h"

// parsing/scene.c
void	scene_init();

// parsing/parse_file.c
t_bool	parse_file(char *filename, t_scene *scene);

// parsing/parse_line.c
t_bool	parse_line(char *line, t_scene *scene);

// parsing/parse_ambiant.c
t_bool	parse_ambiant(char **split, t_scene *scene);
void	ambiant_print(t_scene *scene);

// parsing/parse_camera.c
t_bool	parse_camera(char **split, t_scene *scene);
void	camera_print(t_scene *scene);

// parsing/parse_light.c
t_bool	parse_light(char **split, t_scene *scene);
void	lights_print(t_scene *scene);
void	light_print(t_light light);

// parsing/parse_sphere.c
t_bool	parse_sphere(char **split, t_scene *scene);
void	spheres_print(t_scene *scene);
void	sphere_print(t_sphere sphere);

// parsing/parse_plane.c
t_bool	parse_plane(char **split, t_scene *scene);
void	planes_print(t_scene *scene);
void	plane_print(t_plane plane);

// parsing/parse_cylinder.c
t_bool	parse_cylinder(char **split, t_scene *scene);
void	cylinders_print(t_scene *scene);
void	cylinder_print(t_cylinder cylinder);

// parsing/parse_utils.c
void	ft_free_split(char **tab);
t_bool	check_range_double(double val, double min, double max, char *msg);
t_bool	check_range_int(int val, int min, int max, char *msg);
t_bool	parse_vec(char *str, t_vec *v);
t_bool	parse_color(char *str, t_color *c);

// parsing/is_valid_format.c
t_bool	parse_float(char *src, float *out);
t_bool	parse_int(char *src, int *out);

// parsing/ft_atof.c
double	ft_atof(const char *str);

// parsing/print/scene_infos.c
void	scene_print(t_scene *scene);
void    print_error(char *msg); 
#endif // PARSING_H
