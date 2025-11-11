/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 12:37:45 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/09 10:57:30 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

inline t_vec	vec_proj(const t_vec v, const t_vec w)
{
	return (vec_scal(w, vec_dot(v, w)));
}

inline t_vec	vec_perp(const t_vec v, const t_vec w)
{
	return (vec_sub(v, vec_proj(v, w)));
}

/*
Rotate an vector v around an normalized orthogonal vector w with an angle of a.
*/
inline t_vec	vec_rot(const t_vec *v, const t_vec *w, const t_rad a)
{
	return (vec_sum(vec_scal(*v, cos(a)), vec_scal(vec_cross(*w, *v), sin(a))));
}

void	vec_fmin(t_vec *v, float f)
{
	v->x = fminf(v->x, f);
	v->y = fminf(v->y, f);
	v->z = fminf(v->z, f);
}
