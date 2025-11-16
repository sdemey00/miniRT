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

t_bool	filepath_has_rt(const char *fpath)
{
	char	*ext;

	ext = ft_strrchr(fpath, '.');
	if (!ext || ft_strcmp(ext, ".rt") != 0)
	{
		ft_dprintf(2, "Error\n%s: not a .rt file\n", fpath);
		return (0);
	}
	return (1);
}

static t_bool	open_file(const char *fpath, int *fd)
{
	if (!fpath || !*fpath)
	{
		print_error("No fpath\n");
		return (0);
	}
	if (!filepath_has_rt(fpath))
		return (0);
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
	t_idx	j;

	j = 1;
	line = ft_gnl(fd);
	if (!line)
		return (print_error("Empty file\n"), close(fd), 0);
	while (line)
	{
		if (line[0] && line[0] != '#')
		{
			i = 0;
			while (ft_isspace(line[i]))
				i++;
			if (line[i])
				if (!parse_line(line, scene))
					return (free(line), close(fd),
						ft_dprintf(2, "Line: %d\n", j), 0);
		}
		j++;
		free(line);
		line = ft_gnl(fd);
	}
	return (close(fd), 1);
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
