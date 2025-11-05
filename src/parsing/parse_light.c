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

	if (!split[1] || !split[2] || !split[3] || split[4])
	{
		print_error("Light source: invalid number of arguments\n");
		return (0);
	}
	if (!parse_vec(split[1], &light.pos)
		|| !parse_color(split[3], &light.color))
		return (0);
	if (!parse_float(split[2], &light.brightness))
	{
		print_error("Light source: invalid float format\n");
		return (0);
	}
	if (!check_range_double(light.brightness, 0, 1,
			"Light source: brightness out of range [0, 1]\n"))
		return (0);
	scene->lights[scene->lights_len++] = light;
	return (1);
}

void	light_print(t_light light)
{
	ft_printf("Light source position: %.2f, %.2f, %.2f\n",
		light.pos.x, light.pos.y, light.pos.z);
	ft_printf("Light source brightness: %.2f\n",
		light.brightness);
	ft_printf("Light source color: %d, %d, %d\n", (t_ssuint)light.color.x,
		(t_ssuint)light.color.y, (t_ssuint)light.color.z);
}

void	lights_print(t_light *lights, t_ssuint lights_len)
{
	t_ssuint	i;

	i = 0;
	if (lights_len == 0)
	{
		ft_printf("There is no light sources\n");
		return ;
	}
	ft_printf("\tThere is %d light sources set\n", lights_len);
	ft_printf("- - - - - - - - - - - - - - - - - - - -\n");
	while (i < lights_len)
	{
		ft_printf("Light source %d\n", i + 1);
		light_print(lights[i]);
		if (i != lights_len - 1)
			ft_printf("- - - - - - - - - - - - - - - - - - - -\n");
		i++;
	}
}
