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

	if (!check_args_count(split, 3))
	{
		print_error("Light source: invalid number of arguments\n");
		return (0);
	}
	if (!parse_vec(split[0], &light.pos)
		|| !parse_color(split[2], &light.color)
		|| !parse_float(split[1], &light.intensity)
		|| !check_frange(light.intensity, 0, 1))
		return (0);
	if (scene->lights_len == MAX_OBJS)
		return (print_error("Too much lights\n"), 0);
	scene->lights[scene->lights_len++] = light;
	return (1);
}

void	light_print(const t_light *light)
{
	ft_printf("Light source position: %.2f, %.2f, %.2f\n",
		light->pos.x, light->pos.y, light->pos.z);
	ft_printf("Light source brightness: %.2f\n",
		light->intensity);
	ft_printf("Light source color: %d, %d, %d\n", (t_ssuint)light->color.x,
		(t_ssuint)light->color.y, (t_ssuint)light->color.z);
}

void	lights_print(const t_light *lights, t_ssuint lights_len)
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
		light_print(&lights[i]);
		if (i != lights_len - 1)
			ft_printf("- - - - - - - - - - - - - - - - - - - -\n");
		i++;
	}
}
