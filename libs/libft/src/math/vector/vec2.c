/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 22:16:16 by mmichele          #+#    #+#             */
/*   Updated: 2025/07/11 23:46:14 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Returns the sum of two vectors. */
t_vec	vec_sum(const t_vec a, const t_vec b)
{
	t_vec	res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	res.z = a.z + b.z;
	return (res);
}

/* Returns the difference of two vectors. */
t_vec	vec_sub(const t_vec a, const t_vec b)
{
	t_vec	res;

	res.x = a.x - b.x;
	res.y = a.y - b.y;
	res.z = a.z - b.z;
	return (res);
}

/* Adds a vector to another. */
void	vec_isum(t_vec *dst, const t_vec src)
{
	dst->x += src.x;
	dst->y += src.y;
	dst->z += src.z;
}

/* Substracts a vector to another. */
void	vec_isub(t_vec *dst, const t_vec src)
{
	dst->x -= src.x;
	dst->y -= src.y;
	dst->z -= src.z;
}
