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
	t_vec	normal;
	t_vec	tmp;

	if (obj->e_type == SPH)
	{
		tmp = vec_sub(hit_point, obj->pos);
		normal = vec_norm(tmp);
	}
	else if (obj->e_type == PLA)
		normal = vec_norm(obj->dir);
	else if (obj->e_type == CYL)
	{
		tmp = (t_vec){hit_point.x - obj->pos.x, 0, hit_point.z - obj->pos.z};
		normal = vec_norm(tmp);
	}
	else
		normal = (t_vec){0, 1, 0};
	return (normal);
}
