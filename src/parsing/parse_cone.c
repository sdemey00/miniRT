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

t_bool	parse_cone(char **split, t_scene *scene)
{
	t_obj	cone;

	if (!check_args_count(split, 3))
	{
		print_error("Cone: invalid number of arguments\n");
		return (0);
	}
	if (!parse_vec(split[0], &cone.pos)
		|| !parse_vec(split[1], &cone.dir)
		|| !parse_color(split[2], &cone.color))
		return (0);
	if (!check_range_int(cone.dir.x, -1, 1,
			"Cone: dir vector out of range [-1,1]\n")
		|| !check_range_int(cone.dir.y, -1, 1,
			"Cone: dir vector out of range [-1,1]\n")
		|| !check_range_int(cone.dir.z, -1, 1,
			"Cone: dir vector out of range [-1,1]\n"))
		return (0);
	cone.e_type = CON;
	scene->objs[scene->objs_len++] = cone;
	return (1);
}

void	cone_print(t_obj cone)
{
	ft_printf("Cone pos: %.2f, %.2f, %.2f\n",
		cone.pos.x, cone.pos.y,
		cone.pos.z);
	ft_printf("Cone dir: %.2f, %.2f, %.2f\n",
		cone.dir.x, cone.dir.y,
		cone.dir.z);
	ft_printf("Cone color: %d, %d, %d\n", (t_ssuint)cone.color.x,
		(t_ssuint)cone.color.y, (t_ssuint)cone.color.z);
}
