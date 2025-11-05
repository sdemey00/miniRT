/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 22:02:43 by mmichele          #+#    #+#             */
/*   Updated: 2025/07/10 18:36:31 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "convert_utils/f_convert_utils.h"

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
		n_digit--;
		result += ft_pow(n, n_digit) * (ft_strchr(base, *str));
		str++;
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	short int		positive;
	long int		result;

	while (('\t' <= *str && *str <= '\r') || *str == ' ')
		str++;
	positive = 1;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			positive *= -1;
		str++;
	}
	result = ft_compute(str, base, ft_strlen(base));
	return (result * positive);
}

t_bool	fts_atoi_base(long int *res, char *str, char *base)
{
	short int		positive;
	unsigned int	base_n;

	if (!str || !base || !f_valid_base(base, &base_n))
		return (0);
	while (('\t' <= *str && *str <= '\r') || *str == ' ')
		str++;
	positive = 1;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			positive *= -1;
		str++;
	}
	*res = ft_compute(str, base, base_n);
	return (1);
}
