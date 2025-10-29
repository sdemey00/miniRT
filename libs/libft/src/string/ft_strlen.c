/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:29:49 by mmichele          #+#    #+#             */
/*   Updated: 2025/08/04 21:56:58 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_len	ft_strlen(const char *s)
{
	t_len	res;

	if (!s)
		return (0);
	res = 0;
	while (s[res])
		res++;
	return (res);
}

t_bool	fts_strlen(t_len *res, const char *s)
{
	if (!s)
		return (0);
	*res = 0;
	while (s[*res])
		(*res)++;
	return (1);
}
