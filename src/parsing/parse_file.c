/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemey <sdemey@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:32:37 by sdemey            #+#    #+#             */
/*   Updated: 2025/10/29 12:32:53 by sdemey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	parse_file(char *filename, t_scene *scene)
{
	int		fd;
	char	*line;

	if (!filename || !*filename)
		return (0);
	if (ft_strlen(filename) < 4
		|| ft_strcmp(&filename[ft_strlen(filename) - 3], ".rt") != 0)
		return (ft_dprintf(2, "%s: not a .rt file\n", filename), 0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_dprintf(2, "Cannot open .rt file\n"), 0);
	line = ft_gnl(fd);
	if (!line)
		return (ft_dprintf(2, "Empty file\n"), 0);
	while (line)
	{
		if (line[0] != '\n' && line[0] != '#')
		{
			if (!parse_line(line, scene))
				return (free(line), 0);
		}
		free(line);
		line = ft_gnl(fd);
	}
	return (close(fd), 1);
}
