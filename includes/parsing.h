/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemey <sdemey@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:38:18 by sdemey            #+#    #+#             */
/*   Updated: 2025/11/03 18:12:08 by mmichele         ###   ########.fr       */
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
void	print_ambiant_infos(t_scene *scene);

// parsing/parse_camera.c
t_bool	parse_camera(char **split, t_scene *scene);
void	print_camera_infos(t_scene *scene);

// parsing/parse_light.c
t_bool	parse_light(char **split, t_scene *scene);
void	print_lights_infos(t_scene *scene);

// parsing/parse_sphere.c
t_bool	parse_sphere(char **split, t_scene *scene);
void	print_spheres_infos(t_scene *scene);
void	print_sphere_infos(t_sphere sphere, t_ssuint i);

// parsing/parse_plane.c
t_bool	parse_plane(char **split, t_scene *scene);
void	print_planes_infos(t_scene *scene);

// parsing/parse_cylinder.c
t_bool	parse_cylinder(char **split, t_scene *scene);
void	print_cylinders_infos(t_scene *scene);

// parsing/parse_utils.c
void	ft_free_split(char **tab);
t_bool	check_range_double(double val, double min, double max, char *msg);
t_bool	check_range_int(int val, int min, int max, char *msg);
t_bool	parse_vec(char *str, t_vec *v);
t_bool	parse_color(char *str, t_color *c);

// parsing/ft_atof.c
double	ft_atof(const char *str);

// parsing/print/scene_infos.c
void	print_scene_infos(t_scene *scene);

#endif // PARSING_H
