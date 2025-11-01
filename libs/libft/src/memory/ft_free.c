/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 00:21:13 by mmichele          #+#    #+#             */
/*   Updated: 2025/06/24 00:29:36 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

t_bool	ft_free(void **p, ...)
{
	va_list	args;
	void	**current;

	if (!*p)
		return (0);
	current = p;
	va_start(args, p);
	while (current)
	{
		free(*current);
		*current = 0;
		current = va_arg(args, void **);
	}
	va_end(args);
	return (0);
}
