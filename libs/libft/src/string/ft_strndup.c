/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:30:20 by mmichele          #+#    #+#             */
/*   Updated: 2025/06/03 15:30:56 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, const size_t n)
{
	size_t	i;
	char	*res;

	res = malloc(sizeof(char) * (n + 1));
	if (!res)
		return (0);
	i = 0;
	while (i < n)
	{
		res[i] = s[i];
		i++;
	}
	res[n] = 0;
	return (res);
}
