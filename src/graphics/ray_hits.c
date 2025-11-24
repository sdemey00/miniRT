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
	if (*t < 0.0)
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

t_bool	ray_hit_con(const t_ray *r, const t_obj *co, float *t)
{
	const t_vec	op = vec_sub(r->origin, co->pos);
	const float	cos2 = cosf(FT_PI / 4.0) * cosf(FT_PI / 4.0);
	const float	dv = vec_dot(r->dir, co->dir);
	const float	ov = vec_dot(op, co->dir);
	t_eq2		e;

	e = (t_eq2){dv * dv - cos2, \
				2.0 * (dv * ov - vec_dot(r->dir, op) * cos2), \
				ov * ov - vec_dot(op, op) * cos2, 0, {0, 0}};
	eq2_set(&e);
	if (e.t[0] < INFINITY && e.t[0] < e.t[1])
		*t = e.t[0];
	else if (e.t[1] < INFINITY)
		*t = e.t[1];
	else
		return (0);
	return (1);
}
