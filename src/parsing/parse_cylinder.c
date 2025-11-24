/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemey <sdemey@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:32:33 by sdemey            #+#    #+#             */
/*   Updated: 2025/10/29 12:32:36 by sdemey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	parse_cylinder(char **split, t_scene *scene, void *mlx)
{
	const t_ssuint	min_args = 5;
	const t_ssuint	max_args = min_args + OPTION_ARGS;
	t_obj			cy;

	if (!check_args_range(split, min_args, max_args))
	{
		print_error("Cylinder: invalid number of arguments\n");
		return (0);
	}
	obj_init(&cy);
	if (!parse_vec(split[0], &cy.pos)
		|| !parse_dir(split[1], &cy.dir)
		|| !parse_color(split[4], &cy.color)
		|| !parse_float(split[2], &cy.radius)
		|| !parse_float(split[3], &cy.height)
		|| !parse_optional_args(&split[min_args], &cy, mlx))
		return (0);
	cy.radius /= 2;
	cy.e_type = CYL;
	if (!scene_add_obj(scene, &cy, mlx))
		return (0);
	return (1);
}

void	cylinder_print(const t_obj *cylinder)
{
	ft_printf("Cylinder center: %.2f, %.2f, %.2f\n",
		cylinder->pos.x, cylinder->pos.y,
		cylinder->pos.z);
	ft_printf("Cylinder axis: %.2f, %.2f, %.2f\n",
		cylinder->dir.x, cylinder->dir.y,
		cylinder->dir.z);
	ft_printf("Cylinder radius: %.2f\n",
		cylinder->radius);
	ft_printf("Cylinder height: %.2f\n",
		cylinder->height);
	ft_printf("Cylinder color: %d, %d, %d\n",
		(t_ssuint)cylinder->color.x, (t_ssuint)cylinder->color.y,
		(t_ssuint)cylinder->color.z);
	ft_printf("Cylinder: b=%.2f, r=%.2f\n", cylinder->shininess,
		cylinder->reflexion);
}
