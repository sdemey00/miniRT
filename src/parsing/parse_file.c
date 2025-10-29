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

int	parse_file(char *filename, t_scene *scene)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_dprintf(2, "Cannot open .rt file");
	line = ft_gnl(fd);
	if (line)
	{
		while ((line))
		{
			if (line[0] != '\n' && line[0] != '#')
				parse_line(line, scene);
			free(line);
			line = ft_gnl(fd);
		}
	}
	else
		ft_dprintf(2, "Empty file");
	close(fd);
	return (0);
}
