/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotx.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 00:38:39 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/08 21:42:52 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_vec	vec_rotx(const t_vec v, const t_rad a)
{
	return (mat_mul_vec((t_mat){(t_vec){1, 0, 0}, (t_vec){0, cos(a), -sin(a)}, \
		(t_vec){0, sin(a), cos(a)}}, v));
}

inline void	vec_irotx(t_vec *v, const t_rad a)
{
	*v = vec_rotx(*v, a);
}
