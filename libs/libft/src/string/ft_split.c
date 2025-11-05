/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:40:14 by mmichele          #+#    #+#             */
/*   Updated: 2025/07/13 16:44:25 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_parts(const char *s, const char c)
{
	size_t		count;
	size_t		i;
	int			prev_is_dlm;

	count = 0;
	i = 0;
	prev_is_dlm = 1;
	while (s[i])
	{
		if (s[i] == c)
		{
			if (!prev_is_dlm)
			{
				count++;
				prev_is_dlm = 1;
			}
		}
		else
			prev_is_dlm = 0;
		i++;
	}
	return (count + !prev_is_dlm);
}

static void	free_arr(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

static int	fill_result(char **res, const char *s, char c, size_t r_len)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (j < r_len)
	{
		while (s[i] == c && s[i])
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		if (i > start)
		{
			res[j] = ft_strndup(&s[start], i - start);
			if (!res[j])
				return (0);
			j++;
		}
	}
	return (1);
}

char	**ft_split(const char *s, const char c)
{
	size_t	r_len;
	char	**res;

	if (!s)
		return (0);
	r_len = count_parts(s, c);
	res = malloc((r_len + 1) * sizeof(char *));
	if (!res)
		return (0);
	res[r_len] = 0;
	if (!fill_result(res, s, c, r_len))
	{
		free_arr(res);
		return (0);
	}
	return (res);
}

t_bool	fts_split(char ***res, const char *s, const char c)
{
	*res = ft_split(s, c);
	if (!*res)
		return (0);
	return (1);
}
