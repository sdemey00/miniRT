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

static void	normalize_whitespace(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_isspace(line[i]))
			line[i] = ' ';
		i++;
	}
}

t_bool	parse_line(char *line, t_scene *scene)
{
	char	**split;
	char	status;

	status = -1;
	normalize_whitespace(line);
	split = ft_split(line, ' ');
	if (!split || !split[0])
		return (0);
	if (ft_strcmp(split[0], "A") == 0)
		status = parse_ambiant(&split[1], scene);
	if (ft_strcmp(split[0], "C") == 0)
		status = parse_camera(&split[1], scene);
	if (ft_strcmp(split[0], "L") == 0)
		status = parse_light(&split[1], scene);
	if (ft_strcmp(split[0], "sp") == 0)
		status = parse_sphere(&split[1], scene);
	if (ft_strcmp(split[0], "pl") == 0)
		status = parse_plane(&split[1], scene);
	if (ft_strcmp(split[0], "cy") == 0)
		status = parse_cylinder(&split[1], scene);
	if (ft_strcmp(split[0], "co") == 0)
		status = parse_cone(&split[1], scene);
	if (ft_strcmp(split[0], "ci") == 0)
		status = parse_circle(&split[1], scene);
	ft_free_split(split);
	if (status == -1)
		return (ft_dprintf(2, "Error\nUnexpected identifier\n"), 0);
	return (status);
}
