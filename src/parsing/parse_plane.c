/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemey <sdemey@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:33:09 by sdemey            #+#    #+#             */
/*   Updated: 2025/11/01 18:29:03 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	parse_plane(char **split, t_scene *scene)
{
	t_plane	plane;

	if (!split[1] || !split[2] || !split[3] || split[4])
	{
		print_error("Plane: invalid number of arguments\n");
		return (0);
	}
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

void	plane_print(t_plane plane)
{
	ft_printf("Plane point: %.2f, %.2f, %.2f\n",
		plane.point.x, plane.point.y,
		plane.point.z);
	ft_printf("Plane normal: %.2f, %.2f, %.2f\n",
		plane.normal.x, plane.normal.y,
		plane.normal.z);
	ft_printf("Plane color: %d, %d, %d\n",(t_ssuint)plane.color.x,
		(t_ssuint)plane.color.y, (t_ssuint)plane.color.z);
}

void	planes_print(t_scene *scene)
{
	t_ssuint	i;

	i = 0;
	if (scene->planes_idx == 0)
	{
		ft_printf("There is no planes\n");
		return ;
	}
	ft_printf("\tThere is %d planes set\n", scene->planes_idx);
	ft_printf("- - - - - - - - - - - - - - - - - - - -\n");
	while (i < scene->planes_idx)
	{
		ft_printf("Plane %d\n", i + 1);
		plane_print(scene->planes[i]);
		if (i != scene->planes_idx - 1)
			ft_printf("- - - - - - - - - - - - - - - - - - - -\n");
		i++;
	}
}
