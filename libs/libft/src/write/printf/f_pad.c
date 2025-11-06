/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_pad.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 23:09:49 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/01 00:08:28 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_printf.h"

unsigned int	f_pad(int fd, int size, const unsigned char iszero)
{
	char			c;
	unsigned int	res;

	c = ' ';
	if (iszero)
		c = '0';
	res = 0 ;
	while (size-- > 0)
	{
		if (write(fd, &c, 1) == -1)
			return (res);
		res++;
	}
	return (res);
}
