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

void	parse_sphere(char **split, t_scene *scene)
{
	t_sphere	sp;

	if (!split[1] || !split[2] || !split[3])
		ft_dprintf(2, "Sphere: invalid number of arguments");
	sp.center = parse_vec(split[1]);
	sp.diameter = ft_atof(split[2]);
	sp.color = parse_color(split[3]);
	scene->spheres[scene->spheres_idx++] = sp;
}

void	print_spheres_infos(t_scene *scene)
{
	int	i;

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
		printf("Sphere %d center: %17.2f, %.2f, %.2f\n", i + 1,
			scene->spheres[i].center.x, scene->spheres[i].center.y,
			scene->spheres[i].center.z);
		printf("Sphere %d diameter: %16.2f\n", i + 1,
			scene->spheres[i].diameter);
		printf("Sphere %d color: %16d, %d, %d\n", i + 1,
			scene->spheres[i].color.r, scene->spheres[i].color.g,
			scene->spheres[i].color.b);
		if (i != scene->spheres_idx - 1)
			printf("- - - - - - - - - - - - - - - - - - - -\n");
		i++;
	}
}
