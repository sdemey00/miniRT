/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 22:47:54 by mmichele          #+#    #+#             */
/*   Updated: 2025/10/31 23:53:22 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	vec_print(const t_vec *v)
{
	ft_printf("%f, %f, %f\n", v->x, v->y, v->z);
}

float	vec_mag(const t_vec *v)
{
	return (ft_sqrt(vec_dot(v, v)));
}

float	vec_dot(const t_vec *a, const t_vec *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}
