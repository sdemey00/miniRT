/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambiant.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemey <sdemey@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:32:26 by sdemey            #+#    #+#             */
/*   Updated: 2025/10/29 12:32:28 by sdemey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_ambiant(char **split, t_scene *scene)
{
	t_ambiant	ambiant;

	if (scene->ambiant.set)
		ft_dprintf(2, "Multiple ambiant light definitions are not allowed");
	if (!split[1] || !split[2])
		ft_dprintf(2, "Ambiant light: invalid number of arguments");
	ambiant.ratio = ft_atof(split[1]);
	ambiant.color = parse_color(split[2]);
	scene->ambiant = ambiant;
	scene->ambiant.set = 1;
}

void	print_ambiant_infos(t_scene *scene)
{
	printf("Ambiant light ratio: %.2f\n", scene->ambiant.ratio);
	printf("Ambiant light color: %d, %d, %d\n", scene->ambiant.color.r,
		scene->ambiant.color.g, scene->ambiant.color.b);
}
