/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 22:31:24 by mmichele          #+#    #+#             */
/*   Updated: 2025/10/31 23:53:36 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Returns the multiplication of a vector by a scalar. */
t_vec	vec_scal(const t_vec v, const float scalar)
{
	t_vec	res;

	res.x = v.x * scalar;
	res.y = v.y * scalar;
	res.z = v.z * scalar;
	return (res);
}

/* Returns the division of a vector by a scalar. */
t_vec	vec_rscal(const t_vec v, const float scalar)
{
	t_vec	res;

	res.x = v.x / scalar;
	res.y = v.y / scalar;
	res.z = v.z / scalar;
	return (res);
}

/* Multiplies a vector by a scalar. */
void	vec_iscal(t_vec *src, const float scalar)
{
	src->x *= scalar;
	src->y *= scalar;
	src->z *= scalar;
}

/* Divides a vector by a scalar. */
void	vec_irscal(t_vec *src, const float scalar)
{
	src->x /= scalar;
	src->y /= scalar;
	src->z /= scalar;
}
