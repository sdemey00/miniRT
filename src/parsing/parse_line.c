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
	char				**split;
	char				status;
	t_idx				i;
	const t_obj_build	objects[] = {
	{"A", parse_ambiant}, {"C", parse_camera}, {"L", parse_light},
	{"B", parse_bg}, {"sp", parse_sphere}, {"pl", parse_plane},
	{"cy", parse_cylinder}, {"co", parse_cone}, {"ci", parse_circle},
	{NULL, NULL}};

	i = 0;
	status = -1;
	normalize_whitespace(line);
	split = ft_split(line, ' ');
	if (!split || !split[0])
		return (0);
	while (objects[i].id)
	{
		if (ft_strcmp(split[0], objects[i].id) == 0)
			status = objects[i].func(&split[1], scene);
		i++;
	}
	ft_free_split(split);
	if (status == -1)
		return (ft_dprintf(2, "Error\nUnexpected identifier\n"), 0);
	return (status);
}
