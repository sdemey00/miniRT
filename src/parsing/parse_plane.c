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

int	parse_plane(char **split, t_scene *scene)
{
	t_plane	plane;

	if (!split[1] || !split[2] || !split[3])
		return (ft_dprintf(2, "Plane: invalid number of arguments\n"), -1);
	if (parse_vec(split[1], &plane.point) == -1
		|| parse_vec(split[2], &plane.normal) == -1
		|| parse_color(split[3], &plane.color) == -1)
		return (-1);
	if (!check_range_int(plane.normal.x, -1, 1,
			"Plane: normal vector out of range [-1,1]\n")
		|| !check_range_int(plane.normal.y, -1, 1,
			"Plane: normal vector out of range [-1,1]\n")
		|| !check_range_int(plane.normal.z, -1, 1,
			"Plane: normal vector out of range [-1,1]\n"))
		return (-1);
	scene->planes[scene->planes_idx++] = plane;
	return (0);
}

void	print_planes_infos(t_scene *scene)
{
	int	i;

	i = 0;
	if (scene->planes_idx == 0)
	{
		printf("There is no planes\n");
		return ;
	}
	printf("\tThere is %d planes set\n", scene->planes_idx);
	printf("- - - - - - - - - - - - - - - - - - - -\n");
	while (i < scene->planes_idx)
	{
		printf("Plane %d point: %19.2f, %.2f, %.2f\n", i + 1,
			scene->planes[i].point.x, scene->planes[i].point.y,
			scene->planes[i].point.z);
		printf("Plane %d normal: %18.2f, %.2f, %.2f\n", i + 1,
			scene->planes[i].normal.x, scene->planes[i].normal.y,
			scene->planes[i].normal.z);
		printf("Plane %d color: %16d, %d, %d\n", i + 1,
			scene->planes[i].color.r, scene->planes[i].color.g,
			scene->planes[i].color.b);
		if (i != scene->planes_idx - 1)
			printf("- - - - - - - - - - - - - - - - - - - -\n");
		i++;
	}
}
