/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:25:27 by mmichele          #+#    #+#             */
/*   Updated: 2025/08/04 23:13:38 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	t_len			r_len;
	char			*res;
	unsigned int	i;

	if (!fts_strlen(&r_len, s) || !f)
		return (0);
	res = malloc(sizeof(char) * (r_len + 1));
	if (!res)
		return (0);
	res[r_len] = 0;
	i = 0;
	while (i < r_len)
	{
		res[i] = f(i, s[i]);
		i++;
	}
	return (res);
}
