/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemey <sdemey@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:33:11 by sdemey            #+#    #+#             */
/*   Updated: 2025/10/29 12:33:13 by sdemey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	parse_sphere(char **split, t_scene *scene)
{
	const t_ssuint	min_args = 3;
	const t_ssuint	max_args = min_args + OPTION_ARGS;
	t_obj			sp;

	if (!check_args_range(split, min_args, max_args))
	{
		print_error("Sphere: invalid number of arguments\n");
		return (0);
	}
	sp.brightness = DFLT_BRIGHT;
	sp.reflection = DFLT_REFLECT;
	sp.checkboard = 0;
	if (!parse_vec(split[0], &sp.pos)
		|| !parse_color(split[2], &sp.color)
		|| !parse_float(split[1], &sp.radius)
		|| !parse_optional_args(&split[min_args], &sp))
		return (0);
	sp.radius /= 2;
	sp.e_type = SPH;
	scene->objs[scene->objs_len++] = sp;
	return (1);
}

void	sphere_print(t_obj *sphere)
{
	ft_printf("Sphere center: %.2f, %.2f, %.2f\n",
		sphere->pos.x, sphere->pos.y,
		sphere->pos.z);
	ft_printf("Sphere radius: %.2f\n", sphere->radius);
	ft_printf("Sphere color: %d, %d, %d\n", (t_ssuint)sphere->color.x,
		(t_ssuint)sphere->color.y, (t_ssuint)sphere->color.z);
	ft_printf("Sphere: b=%.2f, r=%.2f, c=%d\n", sphere->brightness,
		sphere->reflection, sphere->checkboard);
}
