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

t_bool	parse_cone(char **split, t_scene *scene, void *mlx)
{
	const t_ssuint	min_args = 3;
	const t_ssuint	max_args = min_args + OPTION_ARGS;
	t_obj			cone;

	if (!check_args_range(split, min_args, max_args))
	{
		print_error("Cone: invalid number of arguments\n");
		return (0);
	}
	obj_init(&cone);
	if (!parse_vec(split[0], &cone.pos)
		|| !parse_dir(split[1], &cone.dir)
		|| !parse_color(split[2], &cone.color)
		|| !parse_optional_args(&split[min_args], &cone, mlx))
		return (0);
	cone.e_type = CON;
	if (!scene_add_obj(scene, &cone))
		return (0);
	return (1);
}

void	cone_print(const t_obj *cone)
{
	ft_printf("Cone pos: %.2f, %.2f, %.2f\n",
		cone->pos.x, cone->pos.y,
		cone->pos.z);
	ft_printf("Cone dir: %.2f, %.2f, %.2f\n",
		cone->dir.x, cone->dir.y,
		cone->dir.z);
	ft_printf("Cone color: %d, %d, %d\n", (t_ssuint)cone->color.x,
		(t_ssuint)cone->color.y, (t_ssuint)cone->color.z);
	ft_printf("Cone: b=%.2f, r=%.2f\n", cone->shininess,
		cone->reflexion);
}
