/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 22:47:54 by mmichele          #+#    #+#             */
/*   Updated: 2025/07/11 23:22:47 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	vec_print(const t_vec *v)
{
	ft_printf("%d, %d, %d\n", (long int)v->x, (long int)v->y, (long int)v->z);
}

double	vec_mag(const t_vec *v)
{
	return (ft_sqrt(vec_dot(v, v)));
}

double	vec_dot(const t_vec *a, const t_vec *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}
