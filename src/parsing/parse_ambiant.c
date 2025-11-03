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
		ft_dprintf(2, "Multiple ambiant light definitions are not allowed\n");
		return (0);
	}
	if (!split[1] || !split[2])
	{
		ft_dprintf(2, "Ambiant light: invalid number of arguments\n");
		return (0);
	}
	if (!parse_float(split[1], &ambiant.ratio))
	{
		ft_dprintf(2, "Invalid vector format\n");
		return (0);
	}
	if (!parse_color(split[2], &ambiant.color))
		return (0);
	scene->ambiant = ambiant;
	scene->ambiant.set = 1;
	return (1);
}

void	ambiant_print(t_scene *scene)
{
	if (scene->ambiant.set != 1)
	{
		printf("There is no ambiant light\n");
		return ;
	}
	printf("Ambiant light ratio: %.2f\n", scene->ambiant.ratio);
	printf("Ambiant light color: %d, %d, %d\n",
		(t_ssuint)scene->ambiant.color.x, (t_ssuint)scene->ambiant.color.y,
		(t_ssuint)scene->ambiant.color.z);
}
