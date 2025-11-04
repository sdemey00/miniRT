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

t_bool	parse_cylinder(char **split, t_scene *scene)
{
	t_cylinder	cylinder;

	if (!split[1] || !split[2] || !split[3] || !split[4] || !split[5] || split[6])
	{
		print_error("Cylinder: invalid number of arguments\n");
		return (0);
	}
	if (!parse_vec(split[1], &cylinder.center)
		|| !parse_vec(split[2], &cylinder.axis)
		|| !parse_color(split[5], &cylinder.color))
		return (0);
	if (!check_range_int(cylinder.axis.x, -1, 1,
			"Cylinder: direction vector out of range [-1,1]\n")
		|| !check_range_int(cylinder.axis.y, -1, 1,
			"Cylinder: direction vector out of range [-1,1]\n")
		|| !check_range_int(cylinder.axis.z, -1, 1,
			"Cylinder: direction vector out of range [-1,1]\n"))
		return (0);
	if (!parse_float(split[3], &cylinder.diameter) || !parse_float(split[4], &cylinder.height))
	{
		print_error("Cylinder: invalid float format\n");
		return (0);
	}
	if ((cylinder.axis.x == 0 && cylinder.axis.y == 0 && cylinder.axis.z == 0)
		|| (cylinder.axis.x == 1 && (cylinder.axis.y == 1 || cylinder.axis.z == 1))
		|| (cylinder.axis.z == 1 && (cylinder.axis.x == 1 || cylinder.axis.y == 1)))
	{
		print_error("Cylinder: invalid direction vector\n");
		return (0);
	}
	scene->cylinders[scene->cylinders_idx++] = cylinder;
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
