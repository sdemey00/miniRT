/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 22:18:15 by mmichele          #+#    #+#             */
/*   Updated: 2025/08/04 23:02:06 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_memadd(void **dst, const void *src, const t_size dst_size, \
	const t_size src_size)
{
	if (!fts_realloc(dst, dst_size, dst_size + src_size))
		return (0);
	ft_memcpy(*dst + dst_size, src, src_size);
	return (1);
}
