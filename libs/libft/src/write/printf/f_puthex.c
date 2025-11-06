/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_puthex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 23:19:27 by mmichele          #+#    #+#             */
/*   Updated: 2025/08/03 18:50:14 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_printf.h"

static unsigned int	print_prefix(const int is_nul, const t_flags *flags)
{
	if (flags->map[E_SHARP] && !is_nul)
	{
		if (flags->format == 'x')
			return (write(flags->fd, "0x", 2));
		else if (flags->format == 'X')
			return (write(flags->fd, "0X", 2));
	}
	return (0);
}

static unsigned int	handle_flag(const t_flags *flags, const unsigned int len, \
	const char *s, const unsigned char is_nul)
{
	unsigned int	res;

	res = 0;
	if (!flags->map[E_MINUS] && (!flags->map[E_ZERO] || flags->map[E_DOT]))
		res += f_pad(flags->fd, flags->padding - ((len < flags->precision) * \
			flags->precision) - ((len >= flags->precision) * len), 0);
	res += print_prefix(is_nul, flags);
	if (!flags->map[E_MINUS] && flags->map[E_ZERO] && !flags->map[E_DOT])
		res += f_pad(flags->fd, flags->padding - len, 1);
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

unsigned int	f_puthex(unsigned int hex, const t_flags *flags)
{
	char	*hex_tab;
	char	dgts[16];
	t_idx	i;

	if (flags->format == 'x')
		hex_tab = "0123456789abcdef";
	else
		hex_tab = "0123456789ABCDEF";
	i = 16;
	if (hex == 0)
		dgts[--i] = '0';
	while (hex != 0)
	{
		dgts[i - 1] = hex_tab[hex % 16];
		hex /= 16;
		i--;
	}
	return (handle_flag(flags, 16 - i, &dgts[i], (i == 15 && dgts[i] == '0')));
}
