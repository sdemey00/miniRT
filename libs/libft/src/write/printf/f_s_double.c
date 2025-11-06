/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_s_double.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 14:53:19 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/02 14:54:10 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_printf.h"

void	s_double_print(const struct s_double *d)
{
	char	bin[64];

	ft_tobin((char *)bin, (void *)&d->val, sizeof(double), 1);
	ft_printf("%.1s.%.11s.%.52s\n", bin, &bin[1], &bin[12]);
}

struct s_double	s_double_init(const double value)
{
	struct s_double	res;

	res.val = value;
	res.sign = (res.bits >> 63) & 1;
	res.exp = ((res.bits >> 52) & 0x7ff);
	res.mant = res.bits & ((1ULL << 52) - 1);
	return (res);
}
