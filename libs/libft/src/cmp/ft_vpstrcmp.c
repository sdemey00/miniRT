/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vpstrcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 21:01:46 by mmichele          #+#    #+#             */
/*   Updated: 2025/08/03 18:50:14 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_sign	ft_vpstrcmp(const void *s1, const void *s2)
{
	const char	*a = s1;
	const char	*b = s2;
	t_idx		i;

	i = 0;
	while (a[i] && b[i] && a[i] == b[i])
		i++;
	if (a[i] < b[i])
		return (-1);
	else if (a[i] == b[i])
		return (0);
	return (1);
}
