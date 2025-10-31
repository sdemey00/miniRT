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

int		parse_file(char *filename, t_scene *scene);
int		parse_line(char *line, t_scene *scene);

int		parse_ambiant(char **split, t_scene *scene);
int		parse_camera(char **split, t_scene *scene);
int		parse_light(char **split, t_scene *scene);
int		parse_sphere(char **split, t_scene *scene);
int		parse_plane(char **split, t_scene *scene);
int		parse_cylinder(char **split, t_scene *scene);

// UTILS
int		parse_vec(char *str, t_vec *v);
int		parse_color(char *str, t_color *c);
int		check_range_double(double val, double min, double max, char *msg);
int		check_range_int(int val, int min, int max, char *msg);
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

#endif
