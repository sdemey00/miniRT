/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemey <sdemey@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:32:37 by sdemey            #+#    #+#             */
/*   Updated: 2025/11/06 18:47:28 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	open_file(const char *fpath, int *fd)
{
	char	*ext;

	if (!fpath || !*fpath)
	{
		print_error("No fpath\n");
		return (0);
	}
	ext = ft_strrchr(fpath, '.');
	if (!ext || ft_strcmp(ext, ".rt") != 0)
	{
		ft_dprintf(2, "Error\n%s: not a .rt file\n", fpath);
		return (0);
	}
	*fd = open(fpath, O_RDONLY);
	if (*fd < 0)
	{
		print_error("Cannot open .rt file\n");
		return (0);
	}
	return (1);
}

static t_bool	parse_all_lines(int fd, t_scene *scene)
{
	char	*line;
	t_idx	i;

	line = ft_gnl(fd);
	if (!line)
	{
		print_error("Empty file\n");
		close(fd);
		return (0);
	}
	while (line)
	{
		if (line[0] && line[0] != '#')
		{
			i = 0;
			while (ft_isspace(line[i]))
				i++;
			if (line[i])
			{
				if (!parse_line(line, scene))
				{
					free(line);
					close(fd);
					return (0);
				}
			}
		}
		free(line);
		line = ft_gnl(fd);
	}
	close(fd);
	return (1);
}

t_bool	parse_file(const char *fpath, t_scene *scene)
{
	int		fd;

	if (!open_file(fpath, &fd))
		return (0);
	if (!parse_all_lines(fd, scene))
		return (0);
	if (!scene->camera.set)
	{
		print_error("Camera is not set\n");
		return (0);
	}
	if (!scene->ambiant.set)
	{
		print_error("Ambiant light is not set\n");
		return (0);
	}
	return (1);
}
