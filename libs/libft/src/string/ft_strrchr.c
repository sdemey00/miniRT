/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:35:22 by mmichele          #+#    #+#             */
/*   Updated: 2025/04/18 23:34:48 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*res;
	unsigned int	i;

	res = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			res = (&((char *)s)[i]);
		i++;
	}
	if ((unsigned char)c == 0)
		return (&((char *)s)[i]);
	return (res);
}
