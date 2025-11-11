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

t_bool	parse_circle(char **split, t_scene *scene)
{
	t_obj	circle;

	if (!check_args_count(split, 3))
	{
		print_error("Circle: invalid number of arguments\n");
		return (0);
	}
	if (!parse_vec(split[0], &circle.pos)
		|| !parse_vec(split[1], &circle.dir)
		|| !parse_color(split[2], &circle.color))
		return (0);
	if (!check_range_int(circle.dir.x, -1, 1,
			"Circle: dir vector out of range [-1,1]\n")
		|| !check_range_int(circle.dir.y, -1, 1,
			"Circle: dir vector out of range [-1,1]\n")
		|| !check_range_int(circle.dir.z, -1, 1,
			"Circle: dir vector out of range [-1,1]\n"))
		return (0);
	circle.e_type = CIR;
	scene->objs[scene->objs_len++] = circle;
	return (1);
}

void	circle_print(t_obj circle)
{
	ft_printf("Circle pos: %.2f, %.2f, %.2f\n",
		circle.pos.x, circle.pos.y,
		circle.pos.z);
	ft_printf("Circle dir: %.2f, %.2f, %.2f\n",
		circle.dir.x, circle.dir.y,
		circle.dir.z);
	ft_printf("Cone color: %d, %d, %d\n", (t_ssuint)circle.color.x,
		(t_ssuint)circle.color.y, (t_ssuint)circle.color.z);
}
