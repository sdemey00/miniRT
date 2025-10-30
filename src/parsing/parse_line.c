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

int	parse_line(char *line, t_scene *scene)
{
	char	**split;
	int		status;

	status = 0;
	split = ft_split(line, ' ');
	if (!split || !split[0])
		return (-1);
	if (ft_strcmp(split[0], "A") == 0)
		status = parse_ambiant(split, scene);
	if (ft_strcmp(split[0], "C") == 0)
		status = parse_camera(split, scene);
	if (ft_strcmp(split[0], "L") == 0)
		status = parse_light(split, scene);
	if (ft_strcmp(split[0], "sp") == 0)
		status = parse_sphere(split, scene);
	if (ft_strcmp(split[0], "pl") == 0)
		status = parse_plane(split, scene);
	if (ft_strcmp(split[0], "cy") == 0)
		status = parse_cylinder(split, scene);
	ft_free_split(split);
	return (status);
}
