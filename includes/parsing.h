/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemey <sdemey@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:38:18 by sdemey            #+#    #+#             */
/*   Updated: 2025/11/06 18:44:39 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minirt.h"

// parsing/scene.c
t_bool	scene_init(t_scene *s, const char *fpath);

// parsing/parse_file.c
t_bool	parse_file(const char *fpath, t_scene *scene);

// parsing/parse_line.c
t_bool	parse_line(char *line, t_scene *scene);

// parsing/parse_ambiant.c
t_bool	parse_ambiant(char **split, t_scene *scene);
void	ambiant_print(t_ambiant ambiant);

// parsing/parse_camera.c
t_bool	parse_camera(char **split, t_scene *scene);
void	camera_print(t_camera camera);

// parsing/parse_light.c
t_bool	parse_light(char **split, t_scene *scene);
void	lights_print(t_light *ligths, t_ssuint lights_len);
void	light_print(t_light light);

// parsing/parse_sphere.c
t_bool	parse_sphere(char **split, t_scene *scene);
void	sphere_print(t_obj sphere);

// parsing/parse_plane.c
t_bool	parse_plane(char **split, t_scene *scene);
void	plane_print(t_obj plane);

// parsing/parse_cylinder.c
t_bool	parse_cylinder(char **split, t_scene *scene);
void	cylinder_print(t_obj cylinder);

// parsing/parse_cone.c
t_bool	parse_cone(char **split, t_scene *scene);
void	cone_print(t_obj cone);

// parsing/parse_circle.c
t_bool	parse_circle(char **split, t_scene *scene);
void	circle_print(t_obj circle);

// parsing/is_valid_format.c
t_bool	check_range_double(double val, double min, double max, char *msg);
t_bool	check_range_int(int val, int min, int max, char *msg);
t_bool	check_args_count(char **tab, const unsigned int count);
t_bool	is_valid_float(char *s);
t_bool	is_valid_int(char *s);

// parsing/parse_utils.c
void	ft_free_split(char **tab);
t_bool	parse_vec(char *str, t_vec *v);
t_bool	parse_color(char *str, t_color *c);
t_bool	parse_float(char *src, float *out);
t_bool	parse_int(char *src, int *out);

// parsing/print_scene_infos.c
void	print_error(char *msg);
void	objs_print(t_obj *objs, t_ssuint objs_len);
void	scene_print(t_scene *scene);

// parsing/ft_atof.c
double	ft_atof(const char *str);

#endif // PARSING_H
