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
	const t_vec	oc = vec_sub(r->origin, s->pos);
	const float	a = vec_dot(r->dir, r->dir);
	const float	b = 2.0 * (vec_dot(r->dir, oc));
	const float	c = vec_dot(oc, oc) - s->radius * s->radius;
	const float	delta = b * b - (4 * a * c);
	float		t0;
	float		t1;

	if (a == 0 || delta < 0)
		return (0);
	t0 = (-b - sqrt(delta)) / (2 * a);
	t1 = (-b + sqrt(delta)) / (2 * a);
	if (t0 > 0.001)
		*t = t0;
	else if (t1 > 0.001)
		*t = t1;
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
	const t_vec	d_perp = vec_perp(r->dir, cy->dir);
	const t_vec	op_perp = vec_perp(op, cy->dir);
	const float	a = vec_dot(d_perp, d_perp);
	const float	b = 2.0 * vec_dot(d_perp, op_perp);
	const float	c = vec_dot(op_perp, op_perp) - (cy->radius * cy->radius);
	const float	delta = b * b - (4 * a * c);
	float		m;
	float		t0;
	float		t1;
	t_obj		ctop;
	t_obj		cbot;

	if (a == 0 || delta < 0)
		return (0);
	t0 = (-b - sqrt(delta)) / (2 * a);
	t1 = (-b + sqrt(delta)) / (2 * a);
	*t = INFINITY;
	if (t0 > 0.005)
	{
		m = vec_dot(vec_sum(op, vec_scal(r->dir, t0)), cy->dir);
		if (!(-cy->height / 2.0 <= m && m <= cy->height / 2.0))
			t0 = INFINITY;
	}
	else
		t0 = INFINITY;
	if (t1 > 0.005)
	{
		m = vec_dot(vec_sum(op, vec_scal(r->dir, t1)), vec_scal(cy->dir, -1));
		if (!(-cy->height / 2.0 <= m && m <= cy->height / 2.0))
			t1 = INFINITY;
	}
	else
		t1 = INFINITY;
	if (t0 < INFINITY && t0 < t1)
		*t = t0;
	else if (t1 < INFINITY && t1 < t0)
		*t = t1;
	if (0.005 > *t)
		*t = INFINITY;
	ctop = *cy;
	ctop.pos = vec_sum(cy->pos, vec_scal(cy->dir, cy->height / 2.0));
	if (ray_hit_cir(r, &ctop, &t0) && t0 < *t && t0 > 0.005)
		*t = t0;
	cbot = *cy;
	cbot.pos = vec_sum(cy->pos, vec_scal(vec_scal(cy->dir, -1), cy->height / 2.0));
	if (ray_hit_cir(r, &cbot, &t1) && t1 < *t && t1 > 0.005)
		*t = t1;
	if (*t < INFINITY)
		return (1);
	return (0);
}
