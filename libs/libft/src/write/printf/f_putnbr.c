/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_putnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 23:13:11 by mmichele          #+#    #+#             */
/*   Updated: 2025/05/31 15:45:26 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_printf.h"
#include <limits.h>

static char	check_neg(int *nbr)
{
	if (*nbr < 0)
	{
		if (*nbr == INT_MIN)
		{
			*nbr = INT_MAX;
			return (-1);
		}
		*nbr *= -1;
		return (1);
	}
	return (0);
}

static unsigned int	print_sign(const int is_neg, const t_flags *flags)
{
	if (!is_neg)
	{
		if (flags->map[E_PLUS])
			return (write(flags->fd, "+", 1));
		else if (flags->map[E_SPACE])
			return (write(flags->fd, " ", 1));
	}
	else
		return (write(flags->fd, "-", 1));
	return (0);
}

static unsigned int	handle_flags(const t_flags *flags, const char *s, \
	const unsigned int len, const int is_neg)
{
	unsigned int	res;
	unsigned char	offset;

	res = 0;
	offset = !!is_neg || (!is_neg && (flags->map[E_PLUS] || \
		flags->map[E_SPACE]));
	if (!flags->map[E_MINUS] && (!flags->map[E_ZERO] || flags->map[E_DOT]))
		res += f_pad(flags->fd, flags->padding - ((len < flags->precision) * \
			flags->precision) - ((len >= flags->precision) * len) - offset, 0);
	res += print_sign(is_neg, flags);
	if (!flags->map[E_MINUS] && flags->map[E_ZERO] && !flags->map[E_DOT])
		res += f_pad(flags->fd, flags->padding - (((len < flags->precision) * \
			flags->precision) + ((len >= flags->precision) * len) + offset), 1);
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

unsigned int	f_putnbr(int nbr, const t_flags *flags)
{
	char			digits[10];
	int				index;
	char			is_neg;

	is_neg = check_neg(&nbr);
	index = 10;
	if (nbr == 0)
		digits[--index] = '0';
	while (nbr != 0)
	{
		digits[index - 1] = '0' + (nbr % 10);
		nbr /= 10;
		index--;
	}
	if (is_neg == -1)
		digits[9]++;
	return (handle_flags(flags, &digits[index], 10 - index, is_neg));
}
