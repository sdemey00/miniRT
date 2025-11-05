/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:40:16 by mmichele          #+#    #+#             */
/*   Updated: 2025/10/31 23:54:49 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_abs(float value)
{
	if (value >= 0)
		return (value);
	return (-value);
}

t_bool	fts_abs(float *value)
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
