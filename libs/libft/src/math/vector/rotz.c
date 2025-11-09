/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotz.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 01:05:31 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/08 21:43:03 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_vec	vec_rotz(const t_vec v, const t_rad a)
{
	return (mat_mul_vec((t_mat){(t_vec){cos(a), -sin(a), 0}, \
		(t_vec){sin(a), cos(a), 0}, (t_vec){0, 0, 1}}, v));
}

inline void	vec_irotz(t_vec *v, const t_rad a)
{
	*v = vec_rotz(*v, a);
}
