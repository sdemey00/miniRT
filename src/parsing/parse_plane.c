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

t_bool	parse_plane(char **split, t_scene *scene)
{
	t_plane	plane;

	if (!split[1] || !split[2] || !split[3])
		return (ft_dprintf(2, "Plane: invalid number of arguments\n"), 0);
	if (!parse_vec(split[1], &plane.point)
		|| !parse_vec(split[2], &plane.normal)
		|| !parse_color(split[3], &plane.color))
		return (0);
	if (!check_range_int(plane.normal.x, -1, 1,
			"Plane: normal vector out of range [-1,1]\n")
		|| !check_range_int(plane.normal.y, -1, 1,
			"Plane: normal vector out of range [-1,1]\n")
		|| !check_range_int(plane.normal.z, -1, 1,
			"Plane: normal vector out of range [-1,1]\n"))
		return (0);
	scene->planes[scene->planes_idx++] = plane;
	return (1);
}

void	print_plane_infos(t_plane plane, t_ssuint i)
{
	printf("Plane %d point: %19.2f, %.2f, %.2f\n", i + 1,
		plane.point.x, plane.point.y,
		plane.point.z);
	printf("Plane %d normal: %18.2f, %.2f, %.2f\n", i + 1,
		plane.normal.x, plane.normal.y,
		plane.normal.z);
	printf("Plane %d color: %16d, %d, %d\n", i + 1,
		plane.color.r, plane.color.g,
		plane.color.b);
}

void	print_planes_infos(t_scene *scene)
{
	t_ssuint	i;

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
		print_plane_infos(scene->planes[i], i);
		if (i != scene->planes_idx - 1)
			printf("- - - - - - - - - - - - - - - - - - - -\n");
		i++;
	}
}
