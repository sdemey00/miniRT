/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:54:19 by mmichele          #+#    #+#             */
/*   Updated: 2025/08/04 23:13:33 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	t_len			s_len;
	t_len			r_len;
	char			*res;
	unsigned int	i;

	if (!fts_strlen(&s_len, s))
		return (0);
	if (start > s_len)
		r_len = 0;
	else
		r_len = s_len - start;
	if (r_len > len)
		r_len = len;
	res = malloc((r_len + 1) * sizeof(char));
	if (!res)
		return (0);
	res[r_len] = '\0';
	i = 0;
	while (i < r_len)
	{
		res[i] = s[i + start];
		i++;
	}
	return (res);
}
