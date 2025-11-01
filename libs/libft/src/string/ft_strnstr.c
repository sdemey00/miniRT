/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:22:27 by mmichele          #+#    #+#             */
/*   Updated: 2025/08/04 23:13:37 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	t_len			l_len;
	t_len			b_len;
	unsigned int	i;

	if (!len || !fts_strlen(&b_len, big) || !fts_strlen(&l_len, little))
		return (0);
	if (b_len < l_len || l_len > len)
		return (0);
	if (!*little && (!*big || !len))
		return ((char *)big);
	i = 0;
	while (i <= len - l_len && big[i])
	{
		if (!ft_strncmp(&big[i], little, l_len))
			return ((char *)&big[i]);
		i++;
	}
	return (0);
}
