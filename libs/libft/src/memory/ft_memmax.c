/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:16:44 by mmichele          #+#    #+#             */
/*   Updated: 2025/08/03 18:50:14 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_idx	ft_memmax(void *mem, t_size unit, t_len len, \
	t_sign (*cmp)(const void *, const void *))
{
	t_idx	i;
	t_idx	res;

	i = 0;
	res = 0;
	while (i < len)
	{
		if (cmp(mem + (res * unit), mem + (i * unit)) < 0)
			res = i;
		i++;
	}
	return (res);
}
