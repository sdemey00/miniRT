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

int	parse_light(char **split, t_scene *scene)
{
	t_light	light;

	if (scene->light.set)
	{
		ft_dprintf(2, "Multiple light source definitions are not allowed\n");
		return (-1);
	}
	if (!split[1] || !split[2] || !split[3])
	{
		ft_dprintf(2, "Light source: invalid number of arguments\n");
		return (-1);
	}
	if (parse_vec(split[1], &light.pos) == -1
		|| parse_color(split[3], &light.color) == -1)
		return (-1);
	light.brightness = ft_atof(split[2]);
	scene->light = light;
	scene->light.set = 1;
	return (0);
}

void	print_light_infos(t_scene *scene)
{
	if (scene->light.set != 1)
	{
		printf("There is no light source\n");
		return ;
	}
	printf("Light source position: %13.2f, %.2f, %.2f\n",
		scene->light.pos.x, scene->light.pos.y, scene->light.pos.z);
	printf("Light source brightness: %9.2f\n",
		scene->light.brightness);
	printf("Light source color: %13d, %d, %d\n",
		scene->ambiant.color.r, scene->ambiant.color.g, scene->ambiant.color.b);
}
