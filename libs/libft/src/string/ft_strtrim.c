/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 18:03:24 by mmichele          #+#    #+#             */
/*   Updated: 2025/08/04 23:13:36 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_len(const char *s, const char *set, const size_t s_len, \
	int idx[2])
{
	size_t	res;
	size_t	i;

	res = 0;
	i = 0;
	while (i < s_len && ft_strchr(set, s[i]) >= 0)
	{
		i++;
		res++;
	}
	idx[0] = i;
	if (i == s_len)
		return (s_len);
	i = s_len - 1;
	while (i > 0 && ft_strchr(set, s[i]) >= 0)
	{
		i--;
		res++;
	}
	idx[1] = i;
	return (s_len - res);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	t_len	s_len;
	t_len	r_len;
	char	*res;
	int		idx[2];

	if (!fts_strlen(&s_len, s1) || !set)
		return (0);
	r_len = count_len(s1, set, s_len, idx);
	res = malloc(sizeof(char) * (r_len + 1));
	if (!res)
		return (0);
	ft_strlcpy(res, &s1[idx[0]], r_len + 1);
	return (res);
}
