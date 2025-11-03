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

	if (!split[1] || !split[2] || !split[3] || !split[4] || !split[5])
	{
		ft_dprintf(2, "Cylinder: invalid number of arguments\n");
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
		ft_dprintf(2, "Invalid vector format\n");
		return (0);
	}
	scene->cylinders[scene->cylinders_idx++] = cylinder;
	return (1);
}

void	print_cylinder_infos(t_cylinder cylinder, t_ssuint i)
{
	printf("Cylinder %d center: %.2f, %.2f, %.2f\n", i + 1,
		cylinder.center.x, cylinder.center.y,
		cylinder.center.z);
	printf("Cylinder %d axis: %.2f, %.2f, %.2f\n", i + 1,
		cylinder.axis.x, cylinder.axis.y,
		cylinder.axis.z);
	printf("Cylinder %d diameter: %.2f\n", i + 1,
		cylinder.diameter);
	printf("Cylinder %d height: %.2f\n", i + 1,
		cylinder.height);
	printf("Cylinder %d color: %d, %d, %d\n", i + 1,
		(t_ssuint)cylinder.color.x, (t_ssuint)cylinder.color.y,
		(t_ssuint)cylinder.color.z);
}

void	print_cylinders_infos(t_scene *scene)
{
	t_ssuint	i;

	i = 0;
	if (scene->cylinders_idx == 0)
	{
		printf("There is no cylinders\n");
		return ;
	}
	printf("\tThere is %d cylinders set\n", scene->cylinders_idx);
	printf("- - - - - - - - - - - - - - - - - - - -\n");
	while (i < scene->cylinders_idx)
	{
		print_cylinder_infos(scene->cylinders[i], i);
		if (i != scene->cylinders_idx - 1)
			printf("- - - - - - - - - - - - - - - - - - - -\n");
		i++;
	}
}
