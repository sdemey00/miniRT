/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_putuint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 23:25:31 by mmichele          #+#    #+#             */
/*   Updated: 2025/05/31 15:20:02 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_printf.h"

static unsigned int	handle_flags(const t_flags *flags, const char *s, \
	const unsigned int len)
{
	unsigned int	res;

	res = 0;
	if (!flags->map[E_MINUS] && (!flags->map[E_ZERO] || flags->map[E_DOT]))
		res += f_pad(flags->fd, flags->padding - (((len < flags->precision) * \
						flags->precision) + ((len >= flags->precision) * \
							len)), 0);
	if (!flags->map[E_MINUS] && flags->map[E_ZERO] && !flags->map[E_DOT])
		res += f_pad(flags->fd, flags->padding - len, 1);
	else if (flags->map[E_DOT])
		res += f_pad(flags->fd, flags->precision - len, 1);
	if (!flags->map[E_DOT] || (flags->map[E_DOT] && flags->precision != 0) \
			|| (*s != '0'))
		res += write(flags->fd, s, len);
	else if (flags->padding)
		res += write(flags->fd, " ", 1);
	if (flags->map[E_MINUS])
		res += f_pad(flags->fd, flags->padding - res, 0);
	return (res);
}

unsigned int	f_putuint(unsigned int nbr, const t_flags *flags)
{
	char				digits[10];
	short unsigned int	index;

	index = 10;
	if (nbr == 0)
		digits[--index] = '0';
	while (nbr != 0)
	{
		digits[index - 1] = '0' + (nbr % 10);
		nbr /= 10;
		index--;
	}
	return (handle_flags(flags, &digits[index], 10 - index));
}
