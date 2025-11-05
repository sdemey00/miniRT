/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 22:47:54 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/05 22:16:36 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline void	vec_print(const t_vec *v)
{
	ft_printf("%.3f, %.3f, %.3f\n", v->x, v->y, v->z);
}

inline float	vec_mag(const t_vec *v)
{
	return (ft_sqrt(vec_dot(v, v)));
}

inline float	vec_dot(const t_vec *a, const t_vec *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}

t_vec	vec_norm(const t_vec *a)
{
	const float	mag = vec_mag(a);

	return ((t_vec){a->x / mag, a->y / mag, a->z / mag});
}

void	vec_inorm(t_vec *a)
{
	const float	mag = vec_mag(a);

	a->x /= mag;
	a->y /= mag;
	a->z /= mag;
}
