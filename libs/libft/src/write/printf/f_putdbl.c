/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_putdbl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:02:50 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/01 00:12:19 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_printf.h"

//ft_printf("%.1s.%.11s.%.52s\n", bin, &bin[1], &bin[12]);
//ft_printf("%.8s.%.8s.%.8s.%.8s.%.8s.%.8s.%.8s.%.8s\n", bin, &bin[8], &bin[16], &bin[24], &bin[32], &bin[40], &bin[48], &bin[56]);
/* 
unsigned int	f_putdbl(const double val, const t_flags *flags)
{
	(void)flags;
	char			bin[64];
	char			res[326];
	const short int	exp;
	const t_luint	mantissa;

	res[0] = 0;
	if (val == INFINITY || val == -INFINITY)
		ft_memcpy(res, "inf", 4);
	//ft_tobin((char *)bin, (void *)&val, sizeof(double), 1);
	//ft_frombin((void *)&exp, (void *)&bin[1], 11, 1);
	//ft_frombin((void *)&mantissa, (void *)&bin[12], 52, 1);
	ft_printf("exp : %d mantiassa : %d\n", exp, mantissa);
	return (0);
}
 */

#include <stdio.h>

unsigned int	f_putdbl(const double val, const t_flags *flags)
{
	(void)flags;

	ft_dprintf(flags->fd, "%d.", (long int)(val));
	ft_dprintf(flags->fd, "%d", (int)((val - (int)val) * 1000) * (ft_pow(-1, (val < 0))));
	return (0);
}