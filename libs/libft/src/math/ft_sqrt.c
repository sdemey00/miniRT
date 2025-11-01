/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 00:27:23 by mmichele          #+#    #+#             */
/*   Updated: 2025/07/11 23:13:14 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_sqrt(const double value)
{
	t_ssuint	approx;
	double		res;

	approx = 10;
	res = 1;
	while (approx--)
		res = (1.0 / 2.0) * (res + ((double)value / (res)));
	return (res);
}
