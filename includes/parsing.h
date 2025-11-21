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

typedef t_bool	(*t_obj_build_fn)(char **split, t_scene *scene, void *mlx);

typedef struct s_obj_build
{
	char			*id;
	t_obj_build_fn	func;
}					t_obj_build;

// parsing/scene_init.c
void	obj_init(t_obj *o);
t_bool	scene_init(t_scene *s, const char *fpath, void *mlx);

// parsing/scene.c
t_bool	scene_add_obj(t_scene *s, t_obj *obj);
void	scene_take_control(t_scene *s, const int x, const int y);
void	scene_change(t_scene *s, const int key);
void	scene_export(t_scene *s);

// parsing/parse_file.c
t_bool	parse_file(const char *fpath, t_scene *scene, void *mlx);

// parsing/parse_line.c
t_bool	parse_line(char *line, t_scene *scene, void *mlx);

// parsing/parse_ambiant.c
t_bool	parse_ambiant(char **split, t_scene *scene, void *mlx);
void	ambiant_print(const t_ambiant *ambiant);

// parsing/parse_camera.c
t_bool	parse_camera(char **split, t_scene *scene, void *mlx);
void	camera_print(const t_camera *camera);

// parsing/parse_light.c
t_bool	parse_light(char **split, t_scene *scene, void *mlx);
void	lights_print(const t_light *ligths, t_ssuint lights_len);
void	light_print(const t_light *light);

// parsing/parse_sphere.c
t_bool	parse_sphere(char **split, t_scene *scene, void *mlx);
void	sphere_print(const t_obj *sphere);

// parsing/parse_plane.c
t_bool	parse_plane(char **split, t_scene *scene, void *mlx);
void	plane_print(const t_obj *plane);

// parsing/parse_cylinder.c
t_bool	parse_cylinder(char **split, t_scene *scene, void *mlx);
void	cylinder_print(const t_obj *cylinder);

// parsing/parse_cone.c
t_bool	parse_cone(char **split, t_scene *scene, void *mlx);
void	cone_print(const t_obj *cone);

// parsing/parse_circle.c
t_bool	parse_circle(char **split, t_scene *scene, void *mlx);
void	circle_print(const t_obj *circle);

// parsing/parse_optional_args.c
t_bool	parse_optional_args(char **split, t_obj *obj, void *mlx);

// parsing/parse_background.c
t_bool	parse_bg(char **split, t_scene *scene, void *mlx);

// parsing/print_scene_infos.c
void	print_error(char *msg);
void	objs_print(const t_obj *objs, t_ssuint objs_len);
void	scene_print(const t_scene *scene);

// parsing/parse_utils/is_valid_format.c
t_bool	is_valid_float(char *s);
t_bool	is_valid_int(char *s);

// parsing/parse_utils/parse_utils.c
t_bool	parse_vec(char *str, t_vec *v);
t_bool	parse_color(char *str, t_color *c);
t_bool	parse_float(char *src, float *out);
t_bool	parse_int(char *src, int *out);
t_bool	parse_dir(char *str, t_vec *v);

// parsing/parse_utils/check_range.c
t_bool	check_frange(const float val, const float min, const float max);
t_bool	check_irange(const int val, const int min, const int max);
t_bool	check_args_count(char **tab, const t_uint count);
t_bool	check_args_range(char **tab, const t_uint min, const t_uint max);

// parsing/parse_utils/ft_atof.c
double	ft_atof(const char *str);

// parsing/parse_utils/free_split.c
void	ft_free_split(char **tab);

#endif // PARSING_H
