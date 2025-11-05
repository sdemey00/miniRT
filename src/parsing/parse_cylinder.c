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

static t_bool	check_cylinder_ranges(t_obj cy)
{
	if (!check_range_int(cy.dir.x, -1, 1,
			"Cylinder: direction vector out of range [-1,1]\n")
		|| !check_range_int(cy.dir.y, -1, 1,
			"Cylinder: direction vector out of range [-1,1]\n")
		|| !check_range_int(cy.dir.z, -1, 1,
			"Cylinder: direction vector out of range [-1,1]\n"))
		return (0);
	if (cy.dir.x == 0 && cy.dir.y == 0 && cy.dir.z == 0)
	{
		print_error("Cylinder: invalid direction vector\n");
		return (0);
	}
	return (1);
}

t_bool	parse_cylinder(char **split, t_scene *scene)
{
	t_obj	cy;

	if (!split[1] || !split[2] || !split[3] || !split[4] || !split[5]
		|| split[6])
	{
		print_error("Cylinder: invalid number of arguments\n");
		return (0);
	}
	if (!parse_vec(split[1], &cy.pos)
		|| !parse_vec(split[2], &cy.dir)
		|| !parse_color(split[5], &cy.color))
		return (0);
	if (!parse_float(split[3], &cy.radius)
		|| !parse_float(split[4], &cy.height))
	{
		print_error("Cylinder: invalid float format\n");
		return (0);
	}
	if (!check_cylinder_ranges(cy))
		return (0);
	cy.radius /= 2;
	cy.e_type = CYLINDER;
	scene->objs[scene->objs_len++] = cy;
	return (1);
}

void	cylinder_print(t_obj cylinder)
{
	ft_printf("Cylinder center: %.2f, %.2f, %.2f\n",
		cylinder.pos.x, cylinder.pos.y,
		cylinder.pos.z);
	ft_printf("Cylinder axis: %.2f, %.2f, %.2f\n",
		cylinder.dir.x, cylinder.dir.y,
		cylinder.dir.z);
	ft_printf("Cylinder radius: %.2f\n",
		cylinder.radius);
	ft_printf("Cylinder height: %.2f\n",
		cylinder.height);
	ft_printf("Cylinder color: %d, %d, %d\n",
		(t_ssuint)cylinder.color.x, (t_ssuint)cylinder.color.y,
		(t_ssuint)cylinder.color.z);
}
