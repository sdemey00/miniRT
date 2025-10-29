/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtobin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 21:53:06 by mmichele          #+#    #+#             */
/*   Updated: 2025/08/03 18:50:14 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_xtobin(const void *mem, const t_size size)
{
	char	*res;
	t_idx	i;
	t_idx	j;

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
			res[(i * 8) + j] = '0' + (((((char *)mem)[i] >> (7 - j))) & 1);
			j++;
		}
		i++;
	}
	return (res);
}
