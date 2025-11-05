/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:22:15 by mmichele          #+#    #+#             */
/*   Updated: 2025/05/24 20:17:44 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf/f_printf.h"

int	ft_dprintf(int fd, const char *s, ...)
{
	int		res;
	va_list	ap;

	va_start(ap, s);
	res = f_vdprintf(fd, s, ap);
	va_end(ap);
	return (res);
}
