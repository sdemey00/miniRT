/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:40:16 by mmichele          #+#    #+#             */
/*   Updated: 2025/07/10 22:56:40 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_abs(double value)
{
	if (value >= 0)
		return (value);
	return (-value);
}

t_bool	fts_abs(double *value)
{
	if (*value <= -FT_DBL_MAX)
		return (0);
	if (*value < 0)
	{
		*value = -(*value);
		return (1);
	}
	return (1);
}
