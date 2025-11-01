/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtobin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 21:53:06 by mmichele          #+#    #+#             */
/*   Updated: 2025/10/29 23:08:38 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tobin(char *res, const void *mem, const t_size size, \
	const t_bool little_endian)
{
	t_idx	i;
	t_idx	j;
	t_byte	*bytes;

	bytes = (t_byte *)mem;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < 8)
		{
			if (little_endian)
				res[(i * 8) + j] = '0' + ((bytes[size - 1 - i] >> (7 - j)) & 1);
			else
				res[(i * 8) + j] = '0' + ((bytes[i] >> (7 - j)) & 1);
			j++;
		}
		i++;
	}
}

char	*ft_xtobin(const void *mem, const t_size size, \
	const t_bool little_endian)
{
	char	*res;
	t_idx	i;
	t_idx	j;
	t_byte	*bytes;

	bytes = (t_byte *)mem;
	res = malloc((sizeof(char) * size * 8) + sizeof(char));
	if (!res)
		return (0);
	res[size * 8] = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < 8)
		{
			if (little_endian)
				res[(i * 8) + j] = '0' + ((bytes[size - 1 - i] >> (7 - j)) & 1);
			else
				res[(i * 8) + j] = '0' + ((bytes[i] >> (7 - j)) & 1);
			j++;
		}
		i++;
	}
	return (res);
}
