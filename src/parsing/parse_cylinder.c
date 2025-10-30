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

void	parse_cylinder(char **split, t_scene *scene)
{
	t_cylinder	cylinder;

	if (!split[1] || !split[2] || !split[3] || !split[4] || !split[5])
		ft_dprintf(2, "Cylinder: invalid number of arguments");
	cylinder.center = parse_vec(split[1]);
	cylinder.axis = parse_vec(split[2]);
	check_range_int(cylinder.axis.x, -1, 1,
		"Cylinder: direction vector out of range [-1,1]");
	check_range_int(cylinder.axis.y, -1, 1,
		"Cylinder: direction vector out of range [-1,1]");
	check_range_int(cylinder.axis.z, -1, 1,
		"Cylinder: direction vector out of range [-1,1]");
	cylinder.diameter = ft_atof(split[3]);
	cylinder.height = ft_atof(split[4]);
	cylinder.color = parse_color(split[5]);
	scene->cylinders[scene->cylinders_idx++] = cylinder;
}

void	print_cylinder_infos(t_cylinder cylinder, int i)
{
	printf("Cylinder %d center: %16.2f, %.2f, %.2f\n", i + 1,
		cylinder.center.x, cylinder.center.y,
		cylinder.center.z);
	printf("Cylinder %d axis: %17.2f, %.2f, %.2f\n", i + 1,
		cylinder.axis.x, cylinder.axis.y,
		cylinder.axis.z);
	printf("Cylinder %d diameter: %14.2f\n", i + 1,
		cylinder.diameter);
	printf("Cylinder %d height: %16.2f\n", i + 1,
		cylinder.height);
	printf("Cylinder %d color: %14d, %d, %d\n", i + 1,
		cylinder.color.r, cylinder.color.g,
		cylinder.color.b);
}

void	print_cylinders_infos(t_scene *scene)
{
	int	i;

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
