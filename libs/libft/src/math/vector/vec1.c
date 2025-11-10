/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 22:47:54 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/08 21:39:19 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline void	vec_print(const t_vec *v)
{
	ft_printf("%.3f, %.3f, %.3f\n", v->x, v->y, v->z);
}

inline float	vec_mag(const t_vec v)
{
	return (ft_sqrt(vec_dot(v, v)));
}

inline float	vec_dot(const t_vec a, const t_vec b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

inline t_vec	vec_norm(const t_vec a)
{
	return (vec_rscal(a, vec_mag(a)));
}

inline void	vec_inorm(t_vec *a)
{
	vec_irscal(a, vec_mag(*a));
}
