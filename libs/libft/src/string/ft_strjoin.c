/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:41:17 by mmichele          #+#    #+#             */
/*   Updated: 2025/08/04 23:12:31 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	t_len	s1_len;
	t_len	s2_len;
	size_t	i;

	if (!fts_strlen(&s1_len, s1) || !s2)
		return (0);
	fts_strlen(&s2_len, s2);
	res = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!res)
		return (0);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		res[s1_len + i] = s2[i];
		i++;
	}
	res[s1_len + i] = '\0';
	return (res);
}
