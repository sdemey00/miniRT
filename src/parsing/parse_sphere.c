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
	t_sphere	sp;

	if (!split[1] || !split[2] || !split[3] || split[4])
	{
		print_error("Sphere: invalid number of arguments\n");
		return (0);
	}
	if (!parse_vec(split[1], &sp.center)
		|| !parse_color(split[3], &sp.color))
		return (0);
	if (!parse_float(split[2], &sp.radius))
	{
		print_error("Sphere: invalid float format\n");
		return (0);
	}
	sp.radius /= 2;
	scene->spheres[scene->spheres_idx++] = sp;
	return (1);
}

void	sphere_print(t_sphere sphere)
{
	ft_printf("Sphere center: %.2f, %.2f, %.2f\n",
		sphere.center.x, sphere.center.y,
		sphere.center.z);
	ft_printf("Sphere radius: %.2f\n", sphere.radius);
	ft_printf("Sphere color: %d, %d, %d\n", (t_ssuint)sphere.color.x,
		(t_ssuint)sphere.color.y, (t_ssuint)sphere.color.z);
}

void	spheres_print(t_scene *scene)
{
	t_ssuint	i;

	i = 0;
	if (scene->spheres_idx == 0)
	{
		ft_printf("There is no spheres\n");
		return ;
	}
	ft_printf("\tThere is %d spheres set\n", scene->spheres_idx);
	ft_printf("- - - - - - - - - - - - - - - - - - - -\n");
	while (i < scene->spheres_idx)
	{
		ft_printf("Sphere %d\n", i + 1);
		sphere_print(scene->spheres[i]);
		if (i != scene->spheres_idx - 1)
			ft_printf("- - - - - - - - - - - - - - - - - - - -\n");
		i++;
	}
}
