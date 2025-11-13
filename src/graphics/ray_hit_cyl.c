/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_hit_cyl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:02:29 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/13 10:49:49 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	check_cyl_height(t_eq2 *e, const t_vec *op, const t_ray *r, \
	const t_obj *cy)
{
	float	m;

	m = vec_dot(vec_sum(*op, vec_scal(r->dir, e->t[0])), cy->dir);
	if (!(-cy->height / 2.0 <= m && m <= cy->height / 2.0))
		e->t[0] = INFINITY;
	m = vec_dot(vec_sum(*op, vec_scal(r->dir, e->t[1])), vec_scal(cy->dir, -1));
	if (!(-cy->height / 2.0 <= m && m <= cy->height / 2.0))
		e->t[1] = INFINITY;
}

t_bool	ray_hit_cyl(const t_ray *r, const t_obj *cy, float *t)
{
	const t_vec	op = vec_sub(r->origin, cy->pos);
	t_eq2		e;
	t_obj		ctop;
	t_obj		cbot;

	e = eq2_init(vec_perp(op, cy->dir), vec_perp(r->dir, cy->dir), cy->radius);
	check_cyl_height(&e, &op, r, cy);
	*t = INFINITY;
	if (e.t[0] < INFINITY && e.t[0] < e.t[1])
		*t = e.t[0];
	else if (e.t[1] < INFINITY)
		*t = e.t[1];
	ctop = *cy;
	ctop.pos = vec_sum(cy->pos, vec_scal(cy->dir, (cy->height / 2.0)));
	if (ray_hit_cir(r, &ctop, &e.t[0]) && e.t[0] < *t)
		*t = e.t[0];
	cbot = *cy;
	cbot.pos = vec_sum(cy->pos, vec_scal(vec_scal(cy->dir, -1), (cy->height / 2.0)));
	if (ray_hit_cir(r, &cbot, &e.t[1]) && e.t[1] < *t)
		*t = e.t[1];
	if (*t < INFINITY)
		return (1);
	return (0);
}
