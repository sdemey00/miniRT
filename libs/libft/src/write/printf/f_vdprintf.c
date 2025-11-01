/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_vdprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:37:36 by mmichele          #+#    #+#             */
/*   Updated: 2025/06/03 14:05:00 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "f_printf.h"

static t_bool	print_invalid_format(t_idxstr *is, int *bytes, t_flags *flags)
{
	t_bool	first_prec;

	if (flags->format == 0)
	{
		*bytes = -1;
		return (0);
	}
	first_prec = 0;
	*bytes += write(flags->fd, "%", 1);
	while (is->s[is->i] && ft_strchr("cspdiuxXf%", is->s[is->i]) < 0)
	{
		if (is->s[is->i] == '.' && !first_prec)
		{
			first_prec = 1;
			if (!('0' <= is->s[is->i + 1] && is->s[is->i + 1] <= '9'))
			{
				*bytes += write(flags->fd, ".0", 2);
				(is->i)++;
			}
		}
		*bytes += write(flags->fd, &is->s[is->i], 1);
		(is->i)++;
	}
	*bytes += write(flags->fd, &is->s[is->i], 1);
	return (1);
}

static t_bool	format(t_idxstr *is, int *bytes, va_list ap, int fd)
{
	t_flags	flags;
	size_t	new_idx;

	new_idx = t_flags_init(&flags, is, fd);
	if (!new_idx)
		return (print_invalid_format(is, bytes, &flags));
	is->i = new_idx;
	if (flags.format == 'c')
		*bytes += f_putchar(va_arg(ap, int), &flags);
	else if (flags.format == 's')
		*bytes += f_putstr(va_arg(ap, char *), &flags);
	else if (flags.format == 'p')
		*bytes += f_putptr(va_arg(ap, long unsigned int), &flags);
	else if (flags.format == 'i' || flags.format == 'd')
		*bytes += f_putnbr(va_arg(ap, int), &flags);
	else if (flags.format == 'u')
		*bytes += f_putuint(va_arg(ap, unsigned int), &flags);
	else if (flags.format == 'x' || flags.format == 'X')
		*bytes += f_puthex(va_arg(ap, long unsigned int), &flags);
	else if (flags.format == '%')
		*bytes += write(fd, "%", 1);
	else if (flags.format == 'f')
		*bytes += f_putdbl(va_arg(ap, double), &flags);
	return (1);
}

int	f_vdprintf(int fd, const char *s, va_list ap)
{
	int			res;
	t_idxstr	is;

	is.i = 0;
	is.s = s;
	if (!s)
		return (-1);
	res = 0;
	while (s[is.i])
	{
		if (s[is.i] == '%')
		{
			is.i++;
			if (!format(&is, &res, ap, fd))
				break ;
		}
		else
			res += write(fd, &s[is.i], 1);
		is.i++;
	}
	return (res);
}
