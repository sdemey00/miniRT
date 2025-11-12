/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambiant.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemey <sdemey@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:32:26 by sdemey            #+#    #+#             */
/*   Updated: 2025/11/01 17:24:24 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	parse_ambiant(char **split, t_scene *scene)
{
	t_ambiant	ambiant;

	if (scene->ambiant.set)
	{
		print_error("Multiple ambiant light definitions are not allowed\n");
		return (0);
	}
	if (!check_args_count(split, 2))
	{
		print_error("Ambiant light: invalid number of arguments\n");
		return (0);
	}
	if (!parse_float(split[0], &ambiant.intensity)
		|| !parse_color(split[1], &ambiant.color)
		|| !check_frange(ambiant.intensity, 0.0, 1.0))
		return (0);
	scene->ambiant = ambiant;
	scene->ambiant.set = 1;
	return (1);
}

void	ambiant_print(t_ambiant *ambiant)
{
	if (ambiant->set != 1)
	{
		ft_printf("There is no ambiant light\n");
		return ;
	}
	ft_printf("Ambiant light ratio: %f\n", ambiant->intensity);
	ft_printf("Ambiant light color: %d, %d, %d\n",
		(t_ssuint)ambiant->color.x, (t_ssuint)ambiant->color.y,
		(t_ssuint)ambiant->color.z);
}
