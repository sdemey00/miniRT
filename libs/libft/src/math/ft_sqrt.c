/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 00:27:23 by mmichele          #+#    #+#             */
/*   Updated: 2025/10/31 23:54:59 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_sqrt(const float value)
{
	t_ssuint	approx;
	float		res;

	approx = 12;
	res = 1;
	while (approx--)
		res = (1.0 / 2.0) * (res + ((float)value / (res)));
	return (res);
}
