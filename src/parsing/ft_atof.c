/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemey <sdemey@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:01:12 by sdemey            #+#    #+#             */
/*   Updated: 2025/07/24 12:16:51 by sdemey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	is_sign(const char **str, double *sign)
{
	if (*(*str) == '+' || *(*str) == '-')
	{
		if (*(*str) == '-')
			*sign *= -1.0;
		(*str)++;
	}
}

double	ft_atof(const char *str)
{
	double	result;
	double	div;
	double	sign;

	result = 0.0;
	div = 1.0;
	sign = 1.0;
	while (ft_isspace(*str))
		str++;
	is_sign(&str, &sign);
	while (ft_isdigit(*str))
	{
		result = result * 10.0 + (*str - '0');
		str++;
	}
	if (*str != '.')
		return (sign * result);
	str++;
	while (ft_isdigit(*str))
	{
		result = result * 10.0 + (*str - '0');
		div *= 10.0;
		str++;
	}
	return (sign * (result / div));
}
