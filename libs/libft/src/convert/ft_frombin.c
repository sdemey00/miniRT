/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frombin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 21:53:06 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/01 00:03:28 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_frombin(void *res, char *bin, const t_len len, \
	const t_bool little_endian)
{
	t_byte			*bytes;
	const t_suint	loops = (len / 8) + 1;
	t_suint			i;
	t_suint			j;
	t_suint			k;

	(void)little_endian;
	bytes = (t_byte *)res;
	i = 0;
	j = len % 8;
	k = 0;
	while (i < loops)
	{
		while (j < 8)
		{
			bytes[i] &= (((bin[k++]) - '0') << j);
			j++;
		}
		j = 0;
		i++;
	}
}
