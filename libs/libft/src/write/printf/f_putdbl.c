/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_putdbl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:02:50 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/05 16:40:39 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_printf.h"

static t_flags	flags_default(const int fd)
{
	t_flags	res;

	ft_bzero(&res, sizeof(t_flags));
	res.fd = fd;
	res.format = 'f';
	return (res);
}

static unsigned int	t_put_dec_part(t_quad dec, const t_flags *flags)
{
	unsigned int	res;
	t_ssuint		i;
	char			dgt;

	res = write(flags->fd, ".", 1);
	i = 6;
	if (flags->map[E_DOT])
		i = flags->precision;
	while (i--)
	{
		dec -= (t_ssuint)dec;
		dec *= 10;
		dgt = (t_ssuint)dec + '0';
		res += write(flags->fd, &dgt, 1);
	}
	return (res);
}

static t_quad	base_case(const struct s_double *dbl, const t_flags *flags)
{
	const t_flags	dflt = flags_default(flags->fd);
	unsigned int	res;
	t_quad			dec;
	t_ssuint		i;

	res = 0;
	dec = 0;
	i = 1;
	while (i < 52)
	{
		dec += ((dbl->mant >> (52 - i)) & 1) * ft_lpow(2.0L, -i);
		i++;
	}
	dec = (1.0L + dec) * ft_lpow(2.0L, dbl->exp - BIASED_EXP);
	res += f_putuint((long unsigned int)dec, &dflt);
	res += t_put_dec_part(dec - (long unsigned int)dec, flags);
	return (res);
}

unsigned int	f_putdbl(const double val, const t_flags *flags)
{
	const struct s_double	dbl = s_double_init(val);
	unsigned int			res;

	res = 0;
	if (dbl.sign)
		res += write(flags->fd, "-", 1);
	if (dbl.exp == ((1 << 11) - 1) && dbl.mant == 0)
		res += write(flags->fd, "inf", 3);
	else if (dbl.exp == ((1 << 11) - 1) && dbl.mant == (1ULL << 51))
		res += write(flags->fd, "nan", 3);
	else
		res += base_case(&dbl, flags);
	return (res);
}
