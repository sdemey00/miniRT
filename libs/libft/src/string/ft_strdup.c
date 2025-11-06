/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:46:01 by mmichele          #+#    #+#             */
/*   Updated: 2025/08/04 23:11:41 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char			*res;
	t_len			s_len;
	unsigned int	i;

	fts_strlen(&s_len, s);
	res = malloc(sizeof(char) * (s_len + 1));
	if (!res)
		return (0);
	res[s_len] = '\0';
	i = 0;
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	return (res);
}
