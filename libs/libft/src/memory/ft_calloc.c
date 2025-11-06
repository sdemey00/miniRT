/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:45:34 by mmichele          #+#    #+#             */
/*   Updated: 2025/05/31 01:42:21 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdint.h>
#include <errno.h>

void	*ft_calloc(unsigned int nmemb, unsigned int size)
{
	void			*res;
	unsigned int	n;

	if ((nmemb && size > (ULONG_MAX / nmemb)) || nmemb * size > 1000000000)
		return (0);
	n = nmemb * size;
	res = malloc(n);
	if (!res)
		return (0);
	ft_bzero(res, n);
	return (res);
}
