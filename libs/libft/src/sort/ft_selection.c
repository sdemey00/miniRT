/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_selection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 20:31:53 by mmichele          #+#    #+#             */
/*   Updated: 2025/08/03 18:50:14 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_idx	f_select(t_byte *mem, t_size unit, t_len len, \
	t_sign (*cmp)(const void *, const void *))
{
	t_idx	min_index;
	t_idx	i;

	min_index = 0;
	i = 1;
	while (i < len)
	{
		if (cmp(mem + (i * unit), mem + (min_index * unit)) < 0)
			min_index = i;
		i++;
	}
	return (min_index);
}

t_bool	ft_selection_sort(void *mem, t_size unit, t_len len, \
	t_sign (*cmp)(const void *, const void *))
{
	t_idx	i;
	t_idx	min_index;

	i = 0;
	while (i < len - 1)
	{
		min_index = f_select(mem + (i * unit), unit, len - i, cmp) + i;
		if (min_index != i)
		{
			if (!ft_memswap(mem + (i * unit), mem + (min_index * unit), unit))
				return (0);
		}
		i++;
	}
	return (1);
}
