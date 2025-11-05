/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:04:37 by mmichele          #+#    #+#             */
/*   Updated: 2025/05/30 22:12:59 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	cnt_dgts(int n)
{
	size_t	res;

	if (n == 0)
		return (1);
	res = (n < 0);
	while (n != 0)
	{
		res++;
		n /= 10;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char			*res;
	size_t			r_len;
	size_t			i;
	unsigned char	sign;

	r_len = cnt_dgts(n);
	res = malloc(sizeof(char) * (r_len + 1));
	if (!res)
		return (0);
	res[r_len] = 0;
	if (n == 0)
		res[0] = '0';
	i = 0;
	sign = (n < 0);
	if (sign)
		res[i] = '-';
	while (i < r_len - sign)
	{
		res[r_len - i - 1] = ft_abs(n % 10) + '0';
		n /= 10;
		i++;
	}
	return (res);
}
