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

t_bool	ray_hit_sphere(const t_ray *r, const t_obj *s, float *t)
{
	const t_vec	oc = vec_sub(r->origin, s->pos);
	const float	a = vec_dot(&r->dir, &r->dir);
	const float	b = 2.0 * (vec_dot(&r->dir, &oc));
	const float	c = vec_dot(&oc, &oc) - s->radius * s->radius;
	const float	delta = b * b - (4 * a * c);

	if (a == 0 || delta < 0.001)
		return (0);
	const float t0 = (-b - sqrt(delta)) / (2 * a);
	const float t1 = (-b + sqrt(delta)) / (2 * a);
	if (t0 > 0.001)
		*t = t0;
	else if (t1 > 0.001)
		*t = t1;
	else
		return (0);
	return (1);
}

t_bool	ray_hit_plane(const t_ray *r, const t_obj *p, float *t)
{
	const t_vec	po = vec_sub(p->pos, r->origin);
	const float	num = vec_dot(&po, &p->dir);
	const float	den = vec_dot(&r->dir, &p->dir);

	if (num == 0 || den == 0)
		return (0);
	*t = num / den;
	if (*t < 0.001)
		return (0);
	return (1);
}

t_bool	ray_hit_circle(const t_ray *r, const t_obj *ci, float *t)
{
	t_vec	p;

	if (!ray_hit_plane(r, ci, t))
		return (0);
	p = vec_sum(r->origin, vec_scal(r->dir, *t));
	t_vec	temp = vec_sub(p, ci->pos);
	if (vec_mag(&temp) <= ci->radius)
		return (1);
	return (0);
}

t_bool	ray_hit_cylinder(const t_ray *r, const t_obj *cy, float *t)
{
	const t_vec op = vec_sub(r->origin, cy->pos);
	const t_vec d_perp = vec_perp(&r->dir, &cy->dir);
	const t_vec op_perp = vec_perp(&op, &cy->dir);

	const float a = vec_dot(&d_perp, &d_perp);
	const float b = 2.0 * vec_dot(&d_perp, &op_perp);
	const float c = vec_dot(&op_perp, &op_perp) - (cy->radius * cy->radius);

	const float	delta = b * b - (4 * a * c);

	if (a == 0 || delta < 0.01)
		return (0);
	const float t0 = (-b - sqrt(delta)) / (2 * a);
	const float t1 = (-b + sqrt(delta)) / (2 * a);

	if (t0 > 0.01)
	{
		t_vec temp1 = vec_sum(op, vec_scal(r->dir, t0));
		float m = vec_dot(&temp1, &cy->dir);
		*t = t0;
		if (-cy->height <= m && m <= cy->height)
			return (1);
	}

	if (t1 > 0.01)
	{
		t_vec temp1 = vec_sum(op, vec_scal(r->dir, t0));
		float m = vec_dot(&temp1, &cy->dir);
		*t = t0;
		if (0 <= m && m <= cy->height)
			return (1);
	}
	// TODO calculate hit with cylinder top and bottom circles.
	return (0);
}
