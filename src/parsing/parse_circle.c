/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemey <sdemey@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:33:09 by sdemey            #+#    #+#             */
/*   Updated: 2025/11/01 18:29:03 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	parse_circle(char **split, t_scene *scene, void *mlx)
{
	const t_ssuint	min_args = 4;
	const t_ssuint	max_args = min_args + OPTION_ARGS;
	t_obj			circle;

	if (!check_args_range(split, min_args, max_args))
	{
		print_error("Circle: invalid number of arguments\n");
		return (0);
	}
	obj_init(&circle);
	if (!parse_vec(split[0], &circle.pos)
		|| !parse_dir(split[1], &circle.dir)
		|| !parse_float(split[2], &circle.radius)
		|| !parse_color(split[3], &circle.color)
		|| !parse_optional_args(&split[min_args], &circle, mlx))
		return (0);
	circle.radius /= 2;
	circle.e_type = CIR;
	if (!scene_add_obj(scene, &circle, mlx))
		return (0);
	return (1);
}

void	circle_print(const t_obj *circle)
{
	ft_printf("Circle pos: %.2f, %.2f, %.2f\n",
		circle->pos.x, circle->pos.y,
		circle->pos.z);
	ft_printf("Circle dir: %.2f, %.2f, %.2f\n",
		circle->dir.x, circle->dir.y,
		circle->dir.z);
	ft_printf("Circle radius: %.2f\n", circle->radius);
	ft_printf("Circle color: %d, %d, %d\n", (t_ssuint)circle->color.x,
		(t_ssuint)circle->color.y, (t_ssuint)circle->color.z);
	ft_printf("Circle: b=%.2f, r=%.2f\n", circle->shininess,
		circle->reflexion);
}
