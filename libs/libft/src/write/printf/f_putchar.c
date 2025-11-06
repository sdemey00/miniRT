/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_putchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 23:15:45 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/01 00:08:07 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_printf.h"

unsigned int	f_putchar(const char chr, const t_flags *flags)
{
	unsigned int	res;

	res = 1;
	if (!flags->map[E_MINUS])
		res += f_pad(flags->fd, flags->padding - 1, 0);
	if (write(flags->fd, &chr, 1) == -1)
		return (res);
	if (flags->map[E_MINUS])
		res += f_pad(flags->fd, flags->padding - 1, 0);
	return (res);
}
