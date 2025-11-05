/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 21:29:28 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/05 22:20:24 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_vec	vec_cross(t_vec a, t_vec b)
{
	return ((t_vec){a.y * b.z - a.z * b.y, \
					a.z * b.x - a.x * b.z, \
					a.x * b.y - a.y * b.x});
}

void	vec_icross(t_vec *a, t_vec b)
{
	*a = (t_vec){a->y * b.z - a->z * b.y, \
				a->z * b.x - a->x * b.z, \
				a->x * b.y - a->y * b.x};
}
