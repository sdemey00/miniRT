/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 08:05:14 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/02 11:27:34 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_utils/f_convert_utils.h"

static char	*ft_allocate(unsigned char sign, unsigned int i, char digits[])
{
	unsigned int	j;
	char			*result;

	result = malloc(sizeof(char) * (sign + MAX_INT_DGTS - i + 1));
	if (!result)
		return (0);
	if (sign)
		result[0] = '-';
	j = sign;
	while (i < MAX_INT_DGTS)
	{
		result[j] = digits[i];
		j++;
		i++;
	}
	result[j] = 0;
	return (result);
}

static char	*ft_putnbr_base(long int decimal, char *base, const unsigned int n)
{
	unsigned char	sign;
	char			digits[MAX_INT_DGTS];
	unsigned int	abs_decimal;
	unsigned int	i;

	sign = 0;
	abs_decimal = decimal;
	if (abs_decimal == 0)
	{
		digits[MAX_INT_DGTS - 1] = '0';
		return (ft_allocate(sign, MAX_INT_DGTS - 1, digits));
	}
	if (decimal < 0)
	{
		abs_decimal *= -1;
		sign = 1;
	}
	i = MAX_INT_DGTS;
	while (abs_decimal != 0)
	{
		i--;
		digits[i] = base[abs_decimal % n];
		abs_decimal /= n;
	}
	return (ft_allocate(sign, i, digits));
}

static long int	ft_compute(const char *str, const char *base, \
	const unsigned int n)
{
	long int		result;
	unsigned int	n_digit;

	result = 0;
	n_digit = 0;
	while (str[n_digit] && ft_strchr(base, str[n_digit]) >= 0)
		n_digit++;
	while (n_digit > 0)
	{
		result += ft_pow(n, n_digit - 1) * (ft_strchr(base, *str));
		str++;
		n_digit--;
	}
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	unsigned int	basef_n;
	unsigned int	baset_n;
	signed char		sign;
	long int		result;

	if (!f_valid_base(base_from, &basef_n) || \
		!f_valid_base(base_to, &baset_n))
		return (0);
	while (('\t' <= *nbr && *nbr <= '\r') || *nbr == ' ')
		nbr++;
	sign = 1;
	while (*nbr == '-' || *nbr == '+')
	{
		if (*nbr == '-')
			sign *= -1;
		nbr++;
	}
	result = ft_compute(nbr, base_from, basef_n) * sign;
	return (ft_putnbr_base(result, base_to, baset_n));
}
