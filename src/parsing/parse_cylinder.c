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

static t_bool	check_cylinder_ranges(t_cylinder cy)
{
	if (!check_range_int(cy.axis.x, -1, 1,
			"Cylinder: direction vector out of range [-1,1]\n")
		|| !check_range_int(cy.axis.y, -1, 1,
			"Cylinder: direction vector out of range [-1,1]\n")
		|| !check_range_int(cy.axis.z, -1, 1,
			"Cylinder: direction vector out of range [-1,1]\n"))
		return (0);
	if ((cy.axis.x == 0 && cy.axis.y == 0 && cy.axis.z == 0)
		|| (cy.axis.x == 1 && (cy.axis.y == 1 || cy.axis.z == 1))
		|| (cy.axis.z == 1 && (cy.axis.x == 1 || cy.axis.y == 1)))
	{
		print_error("Cylinder: invalid direction vector\n");
		return (0);
	}
	return (1);
}

t_bool	parse_cylinder(char **split, t_scene *scene)
{
	t_cylinder	cy;

	if (!split[1] || !split[2] || !split[3] || !split[4] || !split[5]
		|| split[6])
	{
		print_error("Cylinder: invalid number of arguments\n");
		return (0);
	}
	if (!parse_vec(split[1], &cy.center)
		|| !parse_vec(split[2], &cy.axis)
		|| !parse_color(split[5], &cy.color))
		return (0);
	if (!parse_float(split[3], &cy.diameter)
		|| !parse_float(split[4], &cy.height))
	{
		print_error("Cylinder: invalid float format\n");
		return (0);
	}
	if (!check_cylinder_ranges(cy))
		return (0);
	scene->cylinders[scene->cylinders_idx++] = cy;
	return (1);
}

void	cylinder_print(t_cylinder cylinder)
{
	ft_printf("Cylinder center: %.2f, %.2f, %.2f\n",
		cylinder.center.x, cylinder.center.y,
		cylinder.center.z);
	ft_printf("Cylinder axis: %.2f, %.2f, %.2f\n",
		cylinder.axis.x, cylinder.axis.y,
		cylinder.axis.z);
	ft_printf("Cylinder diameter: %.2f\n",
		cylinder.diameter);
	ft_printf("Cylinder height: %.2f\n",
		cylinder.height);
	ft_printf("Cylinder color: %d, %d, %d\n",
		(t_ssuint)cylinder.color.x, (t_ssuint)cylinder.color.y,
		(t_ssuint)cylinder.color.z);
}

void	cylinders_print(t_scene *scene)
{
	t_ssuint	i;

	i = 0;
	if (scene->cylinders_idx == 0)
	{
		ft_printf("There is no cylinders\n");
		return ;
	}
	ft_printf("\tThere is %d cylinders set\n", scene->cylinders_idx);
	ft_printf("- - - - - - - - - - - - - - - - - - - -\n");
	while (i < scene->cylinders_idx)
	{
		ft_printf("Cylinder %d\n", i + 1);
		cylinder_print(scene->cylinders[i]);
		if (i != scene->cylinders_idx - 1)
			ft_printf("- - - - - - - - - - - - - - - - - - - -\n");
		i++;
	}
}
