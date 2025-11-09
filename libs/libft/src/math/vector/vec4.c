/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 21:29:28 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/08 21:44:30 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_vec	vec_cross(const t_vec a, const t_vec b)
{
	return ((t_vec){a.y * b.z - a.z * b.y, \
					a.z * b.x - a.x * b.z, \
					a.x * b.y - a.y * b.x});
}

inline void	vec_icross(t_vec *a, const t_vec b)
{
	*a = (t_vec){a->y * b.z - a->z * b.y, \
				a->z * b.x - a->x * b.z, \
				a->x * b.y - a->y * b.x};
}
