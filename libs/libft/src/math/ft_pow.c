<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:45:11 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/02 13:09:30 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_quad	ft_lpow(const t_quad base, int exp)
{
	t_quad	res;

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

t_luint	ft_pow(const t_uint base, t_uint exp)
{
	t_luint	res;

	res = 1;
	while (exp > 0)
	{
		res *= base;
		exp--;
	}
	return (res);
}
=======
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
>>>>>>> main
