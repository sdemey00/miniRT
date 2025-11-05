/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vpfltcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 22:37:14 by mmichele          #+#    #+#             */
/*   Updated: 2025/06/18 22:38:56 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_sign	ft_vpfltcmp(const void *v1, const void *v2)
{
	const float	a = *(const float *)v1;
	const float	b = *(const float *)v2;

	if (a < b)
		return (-1);
	else if (a == b)
		return (0);
	return (1);
}
