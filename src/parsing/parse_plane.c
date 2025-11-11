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
	t_obj	plane;

	if (!check_args_count(split, 3))
	{
		print_error("Plane: invalid number of arguments\n");
		return (0);
	}
	if (!parse_vec(split[0], &plane.pos)
		|| !parse_vec(split[1], &plane.dir)
		|| !parse_color(split[2], &plane.color))
		return (0);
	if (!check_range_int(plane.dir.x, -1, 1,
			"Plane: dir vector out of range [-1,1]\n")
		|| !check_range_int(plane.dir.y, -1, 1,
			"Plane: dir vector out of range [-1,1]\n")
		|| !check_range_int(plane.dir.z, -1, 1,
			"Plane: dir vector out of range [-1,1]\n"))
		return (0);
	plane.e_type = PLA;
	scene->objs[scene->objs_len++] = plane;
	return (1);
}

void	plane_print(t_obj plane)
{
	ft_printf("Plane pos: %.2f, %.2f, %.2f\n",
		plane.pos.x, plane.pos.y,
		plane.pos.z);
	ft_printf("Plane dir: %.2f, %.2f, %.2f\n",
		plane.dir.x, plane.dir.y,
		plane.dir.z);
	ft_printf("Plane color: %d, %d, %d\n", (t_ssuint)plane.color.x,
		(t_ssuint)plane.color.y, (t_ssuint)plane.color.z);
}
