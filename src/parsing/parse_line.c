/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemey <sdemey@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:32:58 by sdemey            #+#    #+#             */
/*   Updated: 2025/10/29 12:33:07 by sdemey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_line(char *line, t_scene *scene)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split || !split[0])
		return ;
	if (ft_strcmp(split[0], "A") == 0)
		parse_ambiant(split, scene);
	if (ft_strcmp(split[0], "C") == 0)
		parse_camera(split, scene);
	if (ft_strcmp(split[0], "L") == 0)
		parse_light(split, scene);
	if (ft_strcmp(split[0], "sp") == 0)
		parse_sphere(split, scene);
	if (ft_strcmp(split[0], "pl") == 0)
		parse_plane(split, scene);
	if (ft_strcmp(split[0], "cy") == 0)
		parse_cylinder(split, scene);
	ft_free_split(split);
}
