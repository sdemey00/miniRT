/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:49:51 by mmichele          #+#    #+#             */
/*   Updated: 2025/06/18 17:51:47 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, const t_size size)
{
	const unsigned char	*a = s1;
	const unsigned char	*b = s2;
	unsigned int		i;

	if (size == 0)
		return (0);
	i = 0;
	while ((i < size - 1) && a[i] == b[i])
		i++;
	return (a[i] - b[i]);
}
