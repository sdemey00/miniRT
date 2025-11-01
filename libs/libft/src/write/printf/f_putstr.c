/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_putstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 23:17:31 by mmichele          #+#    #+#             */
/*   Updated: 2025/05/31 15:20:02 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_printf.h"

int	f_putstr(const char *str, const t_flags *flags)
{
	unsigned int	len;
	unsigned int	res;

	if (!str && flags->precision >= (6 * flags->map[E_DOT]))
		return (f_putstr("(null)", flags));
	else if (!str && flags->precision < (6 * flags->map[E_DOT]))
		return (f_putstr("", flags));
	len = 0;
	while (str[len])
		len++;
	if (flags->map[E_DOT] && flags->precision < len)
		len = flags->precision;
	res = 0;
	if (!flags->map[E_MINUS])
		res += f_pad(flags->fd, flags->padding - len, 0);
	res += write(flags->fd, str, len);
	if (flags->map[E_MINUS])
		res += f_pad(flags->fd, flags->padding - len, 0);
	return (res);
}
