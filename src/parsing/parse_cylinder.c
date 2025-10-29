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
	ft_lstadd_back((t_list**)&scene->cylinders, (t_list*)&cylinder);
	scene->cylinders[scene->cylinders_idx++] = cylinder;
}

void	print_cylinders_infos(t_scene *scene)
{
	int			i;

	i = 0;
	while (i < scene->cylinders_idx)
	{
		printf("Cylinder %d center: %.2f, %.2f, %.2f\n", i,
			scene->cylinders[i].center.x, scene->cylinders[i].center.y, scene->cylinders[i].center.z);
		printf("Cylinder %d axis: %.2f, %.2f, %.2f\n", i,
			scene->cylinders[i].axis.x, scene->cylinders[i].axis.y, scene->cylinders[i].axis.z);
		printf("Cylinder %d diameter: %.2f\n", i, scene->cylinders[i].diameter);
		printf("Cylinder %d height: %.2f\n", i, scene->cylinders[i].height);
		printf("Cylinder %d color: %d, %d, %d\n", i,
			scene->cylinders[i].color.r, scene->cylinders[i].color.g, scene->cylinders[i].color.b);
		if (i != scene->cylinders_idx)
			printf("- - - - - - - - - - - - - - - - - - - - - - -\n");
		i++;
	}
}
