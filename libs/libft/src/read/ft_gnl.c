/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 23:34:53 by mmichele          #+#    #+#             */
/*   Updated: 2025/07/13 17:09:43 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl/f_gnl.h"

static t_bool	str_init(t_str *s, const size_t init_size)
{
	s->len = 0;
	s->size = init_size;
	s->data = malloc(sizeof(char) * s->size);
	if (!s->data)
		return (0);
	s->data[s->len] = 0;
	return (1);
}

static ssize_t	f_strchri(const t_str *s, size_t i, const char c)
{
	ssize_t	res;

	res = 0;
	while (i + res < s->len)
	{
		if (s->data[i + res] == c)
			return (res);
		res++;
	}
	return (-1);
}

static char	*str_truncate(t_str *s)
{
	char	*res;
	size_t	i;

	res = malloc(sizeof(char) * s->len + 1);
	if (!res)
		return (0);
	i = 0;
	while (i < s->len)
	{
		res[i] = s->data[i];
		i++;
	}
	res[i] = 0;
	str_free(s);
	return (res);
}

char	*ft_gnl(int fd)
{
	static t_buf	safe[MAX_FILES];
	t_str			res;
	ssize_t			ret;
	ssize_t			pos;

	if (fd < 0 || fd >= MAX_FILES || !str_init(&res, STR_INIT_SIZE))
		return (0);
	ret = safe[fd].len;
	if (!str_cut_buf(&res, &safe[fd], 0))
		return (str_free(&res));
	pos = f_strchri(&res, 0, '\n');
	while (pos < 0)
	{
		if (!str_read(&res, fd, &ret))
			return (0);
		if (ret == 0 && res.len)
			return (str_truncate(&res));
		else if (ret == 0 && !res.len)
			return (str_free(&res));
		pos = f_strchri(&res, res.len - ret, '\n');
	}
	if (!buf_cut_str(&safe[fd], &res, res.len - ret + pos + 1))
		return (str_free(&res));
	return (str_truncate(&res));
}

t_bool	fts_gnl(char **line, int fd)
{
	if (fd < 0)
		return (0);
	if (*line)
		free(*line);
	*line = ft_gnl(fd);
	if (!*line)
		return (0);
	return (1);
}
