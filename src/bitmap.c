/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:32:00 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/14 17:43:37 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

inline void	bitmap_switch(t_bitmap *b, t_ssuint i)
{
	*b ^= (1 << i);
}

inline t_bool	bitmap_get(const t_bitmap *b, const t_ssuint i)
{
	return ((*b >> i) & 1);
}

void	bitmap_print(const t_bitmap *b)
{
	t_ssuint	i;

	i = 8;
	while (i--)
	{
		ft_printf("%d", bitmap_get(b, i));
	}
	ft_printf("\n");
}
