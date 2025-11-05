/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_valid_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 21:09:38 by mmichele          #+#    #+#             */
/*   Updated: 2025/08/03 18:50:14 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_convert_utils.h"

t_bool	f_valid_base(const char *base, t_len *bsize)
{
	t_idx	i;
	t_idx	j;

	i = 0;
	while (base[i])
	{
		j = 0;
		while (base[j])
		{
			if (i != j && base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	*bsize = i;
	if (i < 2)
		return (0);
	return (1);
}
