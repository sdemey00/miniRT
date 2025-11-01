/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:24:53 by mmichele          #+#    #+#             */
/*   Updated: 2025/05/24 20:18:21 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf/f_printf.h"

int	ft_printf(const char *s, ...)
{
	int		res;
	va_list	ap;

	va_start(ap, s);
	res = f_vdprintf(1, s, ap);
	va_end(ap);
	return (res);
}
