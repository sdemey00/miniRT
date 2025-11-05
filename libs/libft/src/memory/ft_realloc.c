/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 22:14:46 by mmichele          #+#    #+#             */
/*   Updated: 2025/08/04 22:45:52 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	fts_realloc(void **mem, const t_size old_size, const t_size new_size)
{
	char	*res;

	res = malloc(new_size);
	if (!res)
		return (0);
	ft_memcpy(res, *mem, old_size);
	free(*mem);
	*mem = res;
	return (1);
}
