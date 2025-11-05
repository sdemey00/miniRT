/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:46:39 by mmichele          #+#    #+#             */
/*   Updated: 2025/06/03 14:43:26 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_memcpy(void *dest, const void *src, t_size n)
{
	unsigned int	i;

	if (!dest || !src)
		return (0);
	i = 0;
	while (i < n)
	{
		((t_byte *)dest)[i] = ((t_byte *)src)[i];
		i++;
	}
	return (1);
}
