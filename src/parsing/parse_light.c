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
	if (!parse_float(split[2], &light.brightness))
	{
		ft_dprintf(2, "Invalid vector format\n");
		return (0);
	}
	scene->lights[scene->lights_idx++] = light;
	return (1);
}

void	light_print(t_light light)
{
	printf("Light source position: %.2f, %.2f, %.2f\n",
		light.pos.x, light.pos.y, light.pos.z);
	printf("Light source brightness: %.2f\n",
		light.brightness);
	printf("Light source color: %d, %d, %d\n", (t_ssuint)light.color.x,
		(t_ssuint)light.color.y, (t_ssuint)light.color.z);
}

// void	print_light_infos(t_light light, t_ssuint i)
// {
// 	printf("Light source %d position: %.2f, %.2f, %.2f\n", i + 1,
// 		light.pos.x, light.pos.y, light.pos.z);
// 	printf("Light source %d brightness: %.2f\n", i + 1,
// 		light.brightness);
// 	printf("Light source %d color: %d, %d, %d\n", i + 1, (t_ssuint)light.color.x,
// 		(t_ssuint)light.color.y, (t_ssuint)light.color.z);
// }

void	lights_print(t_scene *scene)
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
		printf("Light source %d\n", i);
		light_print(scene->lights[i]);
		if (i != scene->lights_idx - 1)
			printf("- - - - - - - - - - - - - - - - - - - -\n");
		i++;
	}
}
