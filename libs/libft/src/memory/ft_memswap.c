/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 01:35:35 by mmichele          #+#    #+#             */
/*   Updated: 2025/05/24 20:30:35 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_memswap(void *a, void *b, t_size unit)
{
	t_byte	*temp;

	if (!a || !b)
		return (0);
	temp = malloc(unit);
	if (!temp)
		return (0);
	ft_memcpy(temp, a, unit);
	ft_memcpy(a, b, unit);
	ft_memcpy(b, temp, unit);
	free(temp);
	return (1);
}
