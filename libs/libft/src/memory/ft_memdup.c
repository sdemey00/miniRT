/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:31:28 by mmichele          #+#    #+#             */
/*   Updated: 2025/06/03 15:11:12 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *src, const t_size unit, const t_len n)
{
	void	*res;

	res = malloc(unit * n);
	if (!res)
		return (0);
	if (!ft_memcpy(res, src, unit * n))
	{
		free(res);
		return (0);
	}
	return (res);
}

t_bool	fts_memdup(void **dst, const void *src, const t_size unit, \
	const t_len n)
{
	*dst = malloc(unit * n);
	if (!*dst)
		return (0);
	if (!ft_memcpy(*dst, src, unit * n))
	{
		free(*dst);
		*dst = 0;
		return (0);
	}
	return (1);
}
