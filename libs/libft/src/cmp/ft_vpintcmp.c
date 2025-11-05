/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 21:01:26 by mmichele          #+#    #+#             */
/*   Updated: 2025/06/07 11:45:29 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_sign	ft_vpintcmp(const void *v1, const void *v2)
{
	const int	a = *(const int *)v1;
	const int	b = *(const int *)v2;

	if (a < b)
		return (-1);
	else if (a == b)
		return (0);
	return (1);
}
