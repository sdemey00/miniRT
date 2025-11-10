/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_hits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:16:11 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/04 17:48:28 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	ray_hit_sph(const t_ray *r, const t_obj *s, float *t)
{
	const t_eq2	e = eq2_init(vec_sub(r->origin, s->pos), r->dir, s->radius);

	if (e.t[0] < INFINITY && e.t[0] < e.t[1])
		*t = e.t[0];
	else if (e.t[1] < INFINITY)
		*t = e.t[1];
	else
		return (0);
	return (1);
}

t_bool	ray_hit_pla(const t_ray *r, const t_obj *p, float *t)
{
	const t_vec	po = vec_sub(p->pos, r->origin);
	const float	num = vec_dot(po, p->dir);
	const float	den = vec_dot(r->dir, p->dir);

	if (num == 0 || den == 0)
		return (0);
	*t = num / den;
	if (*t < 0.001)
		return (0);
	return (1);
}

t_bool	ray_hit_cir(const t_ray *r, const t_obj *ci, float *t)
{
	t_vec	p;

	if (!ray_hit_pla(r, ci, t))
		return (0);
	p = vec_sum(r->origin, vec_scal(r->dir, *t));
	if (vec_mag(vec_sub(p, ci->pos)) <= ci->radius)
		return (1);
	return (0);
}

t_bool	ray_hit_cyl(const t_ray *r, const t_obj *cy, float *t)
{
	const t_vec	op = vec_sub(r->origin, cy->pos);
	t_eq2		e;
	float		m;
	t_obj		ctop;
	t_obj		cbot;

	e = eq2_init(vec_perp(op, cy->dir), vec_perp(r->dir, cy->dir), cy->radius);
	m = vec_dot(vec_sum(op, vec_scal(r->dir, e.t[0])), cy->dir);
	if (!(-cy->height / 2.0 <= m && m <= cy->height / 2.0))
		e.t[0] = INFINITY;
	m = vec_dot(vec_sum(op, vec_scal(r->dir, e.t[1])), vec_scal(cy->dir, -1));
	if (!(-cy->height / 2.0 <= m && m <= cy->height / 2.0))
		e.t[1] = INFINITY;
	*t = INFINITY;
	if (e.t[0] < INFINITY && e.t[0] < e.t[1])
		*t = e.t[0];
	else if (e.t[1] < INFINITY)
		*t = e.t[1];
	ctop = *cy;
	ctop.pos = vec_sum(cy->pos, vec_scal(cy->dir, (cy->height / 2.0) + 0.003));
	if (ray_hit_cir(r, &ctop, &e.t[0]) && e.t[0] < *t && e.t[0] > 0.005)
		*t = e.t[0];
	cbot = *cy;
	cbot.pos = vec_sum(cy->pos, vec_scal(vec_scal(cy->dir, -1), (cy->height / 2.0) + 0.003));
	if (ray_hit_cir(r, &cbot, &e.t[1]) && e.t[1] < *t && e.t[1] > 0.005)
		*t = e.t[1];
	if (*t < INFINITY)
		return (1);
	return (0);
}

//t_bool	ray_hit_con(const t_ray *r, const t_obj *cy, float *t)
//{
//
//}
