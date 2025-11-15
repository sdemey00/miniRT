/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_surface_normal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:34:52 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/11 17:34:53 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	get_surface_normal(t_obj *obj, t_vec hit_point)
{
	if (obj->e_type == SPH)
		return (vec_norm(vec_sub(hit_point, obj->pos)));
	else if (obj->e_type == PLA || obj->e_type == CIR)
		return (vec_norm(obj->dir));
	else if (obj->e_type == CYL)
		return (vec_norm((t_vec){
				hit_point.x - obj->pos.x, 0, hit_point.z - obj->pos.z}));
	// else if (obj->e_type == CON)
	// {
	// }
	return ((t_vec){0, 1, 0});
}
