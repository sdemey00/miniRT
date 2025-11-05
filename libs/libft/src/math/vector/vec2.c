/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 22:16:16 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/05 22:19:24 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Returns the sum of two vectors. */
inline t_vec	vec_sum(const t_vec a, const t_vec b)
{
	return ((t_vec){a.x + b.x, a.y + b.y, a.z + b.z});
}

/* Returns the difference of two vectors. */
inline t_vec	vec_sub(const t_vec a, const t_vec b)
{
	return ((t_vec){a.x - b.x, a.y - b.y, a.z - b.z});
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
