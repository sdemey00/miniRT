/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_hit_bh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 00:00:00 by mmichele          #+#    #+#             */
/*   Updated: 2026/04/15 23:22:39 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	ray_hit_bh(const t_ray *r, const t_obj *bh, float *t)
{
	const t_eq2	e = eq2_init(vec_sub(r->origin, bh->pos), r->dir, bh->radius);

	if (e.t[0] < INFINITY && e.t[0] < e.t[1])
		*t = e.t[0];
	else if (e.t[1] < INFINITY)
		*t = e.t[1];
	else
		return (0);
	return (1);
}
