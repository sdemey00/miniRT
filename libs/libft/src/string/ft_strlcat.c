/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:23:00 by mmichele          #+#    #+#             */
/*   Updated: 2025/08/04 23:12:41 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	t_len	d_len;
	t_len	s_len;
	size_t	i;
	size_t	j;

	if (!size || !fts_strlen(&d_len, dst) || !fts_strlen(&s_len, src))
		return (0);
	i = d_len;
	j = 0;
	while (src[j] && i + 1 < size)
		dst[i++] = src[j++];
	dst[i] = 0;
	if (size < d_len)
		return (size + s_len);
	return (d_len + s_len);
}
