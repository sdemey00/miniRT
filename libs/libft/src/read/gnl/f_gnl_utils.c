/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_gnl_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 00:35:10 by mmichele          #+#    #+#             */
/*   Updated: 2025/05/27 13:36:03 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_gnl.h"

char	*str_free(t_str *s)
{
	if (!s || !s->data)
		return (0);
	free(s->data);
	s->data = 0;
	return (0);
}

static t_bool	str_extend(t_str *s, const size_t scalar)
{
	char	*new;
	size_t	i;

	s->size *= scalar;
	new = malloc(sizeof(char) * (s->size));
	if (!new)
	{
		str_free(s);
		return (0);
	}
	i = 0;
	while (i < s->len)
	{
		new[i] = s->data[i];
		i++;
	}
	new[i] = 0;
	free(s->data);
	s->data = new;
	return (1);
}

t_bool	str_read(t_str *s, const int fd, ssize_t *ret)
{
	while (s->size - s->len - 1 < BUFFER_SIZE)
	{
		if (!str_extend(s, STR_SCALE))
			return (0);
	}
	*ret = read(fd, &s->data[s->len], BUFFER_SIZE);
	if (*ret < 0)
	{
		str_free(s);
		return (0);
	}
	s->len += *ret;
	s->data[s->len] = 0;
	return (1);
}

t_bool	str_cut_buf(t_str *dst, t_buf *src, const size_t i)
{
	size_t	j;

	while (dst->size - dst->len - 1 < src->len)
	{
		if (!str_extend(dst, STR_SCALE))
			return (0);
	}
	j = 0;
	while (i + j < src->len)
	{
		dst->data[j] = src->data[i + j];
		j++;
	}
	dst->len = j;
	dst->data[j] = 0;
	src->len = i;
	src->data[i] = 0;
	return (1);
}

t_bool	buf_cut_str(t_buf *dst, t_str *src, const size_t i)
{
	size_t	j;

	j = 0;
	while (i + j < src->len)
	{
		dst->data[j] = src->data[i + j];
		j++;
	}
	dst->len = j;
	dst->data[j] = 0;
	src->len = i;
	src->data[i] = 0;
	return (1);
}
