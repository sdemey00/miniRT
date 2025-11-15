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

t_bool	parse_plane(char **split, t_scene *scene)
{
	const t_ssuint	min_args = 3;
	const t_ssuint	max_args = min_args + OPTION_ARGS;
	t_obj			plane;

	if (!check_args_range(split, min_args, max_args))
	{
		print_error("Plane: invalid number of arguments\n");
		return (0);
	}
	obj_init(&plane);
	if (!parse_vec(split[0], &plane.pos)
		|| !parse_dir(split[1], &plane.dir)
		|| !parse_color(split[2], &plane.color)
		|| !parse_optional_args(&split[min_args], &plane))
		return (0);
	plane.e_type = PLA;
	scene->objs[scene->objs_len++] = plane;
	return (1);
}

void	plane_print(const t_obj *plane)
{
	ft_printf("Plane pos: %.2f, %.2f, %.2f\n",
		plane->pos.x, plane->pos.y,
		plane->pos.z);
	ft_printf("Plane dir: %.2f, %.2f, %.2f\n",
		plane->dir.x, plane->dir.y,
		plane->dir.z);
	ft_printf("Plane color: %d, %d, %d\n", (t_ssuint)plane->color.x,
		(t_ssuint)plane->color.y, (t_ssuint)plane->color.z);
	ft_printf("Plane: b=%.2f, r=%.2f\n", plane->shininess, plane->reflexion);
}
