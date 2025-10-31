/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemey <sdemey@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:32:54 by sdemey            #+#    #+#             */
/*   Updated: 2025/10/29 12:32:56 by sdemey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	parse_light(char **split, t_scene *scene)
{
	t_light	light;

	if (!split[1] || !split[2] || !split[3])
	{
		ft_dprintf(2, "Light source: invalid number of arguments\n");
		return (0);
	}
	if (!parse_vec(split[1], &light.pos)
		|| !parse_color(split[3], &light.color))
		return (0);
	light.brightness = ft_atof(split[2]);
	scene->light[scene->lights_idx++] = light;
	return (1);
}

void	print_lights_infos(t_scene *scene)
{
	t_ssuint	i;

	i = 0;
	if (scene->lights_idx == 0)
	{
		printf("There is no light sources\n");
		return ;
	}
	printf("\tThere is %d light sources set\n", scene->lights_idx);
	printf("- - - - - - - - - - - - - - - - - - - -\n");
	while (i < scene->lights_idx)
	{
		printf("Light source %d position: %13.2f, %.2f, %.2f\n", i,
			scene->light[i].pos.x, scene->light[i].pos.y, scene->light[i].pos.z);
		printf("Light source %d brightness: %9.2f\n", i,
			scene->light[i].brightness);
		printf("Light source %d color: %13d, %d, %d\n", i,
			scene->light[i].color.r, scene->light[i].color.g, scene->light[i].color.b);
		if (i != scene->lights_idx - 1)
			printf("- - - - - - - - - - - - - - - - - - - -\n");
		i++;
	}
}