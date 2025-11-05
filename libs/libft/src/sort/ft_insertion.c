/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 20:17:44 by mmichele          #+#    #+#             */
/*   Updated: 2025/08/03 18:50:14 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_insertion_sort(void *mem, t_size unit, t_len len, \
	t_sign (*cmp)(const void *, const void *))
{
	t_idx	i;
	t_idx	insert;

	i = 1;
	while (i < len)
	{
		insert = i;
		while (insert > 0)
		{
			if (cmp(mem + ((insert * unit) - (1 * unit)), \
				mem + (insert * unit)) > 0)
			{
				if (!ft_memswap(mem + ((insert * unit) - (1 * unit)), \
					mem + (insert * unit), unit))
					return (0);
			}
			else
				break ;
			insert--;
		}
		i++;
	}
	return (1);
}
