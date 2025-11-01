/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pythagoras.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:46:57 by mmichele          #+#    #+#             */
/*   Updated: 2025/07/11 23:22:02 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_pythagoras(const float a, const float b)
{
	return (ft_sqrt(ft_pow(a, 2) + ft_pow(b, 2)));
}
