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

	if (!split[1] || !split[2] || !split[3])
	{
		ft_dprintf(2, "Sphere: invalid number of arguments\n");
		return (0);
	}
	if (!parse_vec(split[1], &sp.center)
		|| !parse_color(split[3], &sp.color))
		return (0);
	if (!parse_float(split[2], &sp.diameter))
	{
		ft_dprintf(2, "Invalid vector format\n");
		return (0);
	}
	scene->spheres[scene->spheres_idx++] = sp;
	return (1);
}

void	sphere_print(t_sphere sphere)
{
	printf("Sphere center: %.2f, %.2f, %.2f\n",
		sphere.center.x, sphere.center.y,
		sphere.center.z);
	printf("Sphere diameter: %.2f\n", sphere.diameter);
	printf("Sphere color: %d, %d, %d\n", (t_ssuint)sphere.color.x,
		(t_ssuint)sphere.color.y, (t_ssuint)sphere.color.z);
}

// void	print_sphere_infos(t_sphere sphere, t_ssuint i)
// {
// 	printf("Sphere %d center: %.2f, %.2f, %.2f\n", i + 1,
// 		sphere.center.x, sphere.center.y,
// 		sphere.center.z);
// 	printf("Sphere %d diameter: %.2f\n", i + 1,
// 		sphere.diameter);
// 	printf("Sphere %d color: %d, %d, %d\n", i + 1, (t_ssuint)sphere.color.x,
// 		(t_ssuint)sphere.color.y, (t_ssuint)sphere.color.z);
// }

void	spheres_print(t_scene *scene)
{
	t_ssuint	i;

	i = 0;
	if (scene->spheres_idx == 0)
	{
		printf("There is no spheres\n");
		return ;
	}
	printf("\tThere is %d spheres set\n", scene->spheres_idx);
	printf("- - - - - - - - - - - - - - - - - - - -\n");
	while (i < scene->spheres_idx)
	{
		printf("Sphere %d\n", i);
		sphere_print(scene->spheres[i]);
		if (i != scene->spheres_idx - 1)
			printf("- - - - - - - - - - - - - - - - - - - -\n");
		i++;
	}
}
