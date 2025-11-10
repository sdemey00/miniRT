/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roty.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 01:05:45 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/08 21:43:01 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_vec	vec_roty(const t_vec v, const t_rad a)
{
	return (mat_mul_vec((t_mat){(t_vec){cos(a), 0, sin(a)}, (t_vec){0, 1, 0}, \
		(t_vec){-sin(a), 0, cos(a)}}, v));
}

inline void	vec_iroty(t_vec *v, const t_rad a)
{
	*v = vec_roty(*v, a);
}
