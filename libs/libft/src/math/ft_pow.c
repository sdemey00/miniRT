/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:45:11 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/05 22:28:49 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_pow(const float base, int exp)
{
	float	res;

	res = 1;
	if (exp > 0)
	{
		while (exp--)
			res *= base;
	}
	else if (exp < 0)
	{
		while (exp++)
			res /= base;
	}
	return (res);
}
