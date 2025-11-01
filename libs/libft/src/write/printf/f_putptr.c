/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_putptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 23:24:24 by mmichele          #+#    #+#             */
/*   Updated: 2025/05/31 16:20:21 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_printf.h"

static unsigned int	print_prefix(const t_flags *flags)
{
	size_t	res;

	res = 0;
	if (flags->map[E_PLUS])
		res += write(flags->fd, "+", 1);
	else if (flags->map[E_SPACE])
		res += write(flags->fd, " ", 1);
	res += write(flags->fd, "0x", 2);
	return (res);
}

static unsigned int	handle_flag(const t_flags *flags, const unsigned int len, \
	const char *s)
{
	unsigned int	res;

	res = 0;
	if (!flags->map[E_MINUS] && (!flags->map[E_ZERO] || flags->map[E_DOT]))
		res += f_pad(flags->fd, flags->padding - ((len < flags->precision) * \
			flags->precision) - ((len >= flags->precision) * len) - 2 - \
				(flags->map[E_PLUS] || flags->map[E_SPACE]), 0);
	res += print_prefix(flags);
	if (!flags->map[E_MINUS] && flags->map[E_ZERO] && !flags->map[E_DOT])
		res += f_pad(flags->fd, flags->padding - len - 2, 1);
	else if (flags->map[E_DOT])
		res += f_pad(flags->fd, flags->precision - len, 1);
	if (!flags->map[E_DOT] || (flags->map[E_DOT] && flags->precision) \
		|| (*s != '0'))
		res += write(flags->fd, s, len);
	else if (flags->padding)
		res += write(flags->fd, " ", 1);
	if (flags->map[E_MINUS])
		res += f_pad(flags->fd, flags->padding - res, 0);
	return (res);
}

unsigned int	f_putptr(long unsigned int ptr, const t_flags *flags)
{
	const char		*hex_tab = "0123456789abcdef";
	char			digits[16];
	unsigned int	index;

	if (!ptr)
	{
		((t_flags *)flags)->precision = 5;
		return (f_putstr("(nil)", flags));
	}
	index = 16;
	if (ptr == 0)
		digits[--index] = '0';
	while (ptr != 0)
	{
		digits[index - 1] = hex_tab[ptr % 16];
		ptr /= 16;
		index--;
	}
	return (handle_flag(flags, 16 - index, &digits[index]));
}
