/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemey <sdemey@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:33:09 by sdemey            #+#    #+#             */
/*   Updated: 2025/10/29 12:33:10 by sdemey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_plane(char **split, t_scene *scene)
{
	t_plane	plane;

	if (!split[1] || !split[2] || !split[3])
		ft_dprintf(2, "Plane: invalid number of arguments");
	plane.point = parse_vec(split[1]);
	plane.normal = parse_vec(split[2]);
	check_range_int(plane.normal.x, -1, 1,
		"Plane: normal vector out of range [-1,1]");
	check_range_int(plane.normal.y, -1, 1,
		"Plane: normal vector out of range [-1,1]");
	check_range_int(plane.normal.z, -1, 1,
		"Plane: normal vector out of range [-1,1]");
	plane.color = parse_color(split[3]);
	scene->planes[scene->planes_idx++] = plane;
}

void	print_planes_infos(t_scene *scene)
{
	int			i;


	i = 0;
	while (i < scene->planes_idx)
	{
		printf("Plane %d point: %.2f, %.2f, %.2f\n", i,
			scene->planes[i].point.x, scene->planes[i].point.y, scene->planes[i].point.z);
		printf("Plane %d normal: %.2f, %.2f, %.2f\n", i,
			scene->planes[i].normal.x, scene->planes[i].normal.y, scene->planes[i].normal.z);
		printf("Plane %d color: %d, %d, %d\n", i,
			scene->planes[i].color.r, scene->planes[i].color.g, scene->planes[i].color.b);
		if (i != scene->planes_idx)
			printf("- - - - - - - - - - - - - - - - - - - - - - -\n");
		i++;
	}
}