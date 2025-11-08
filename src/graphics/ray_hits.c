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

t_bool	ray_hit_sphere(const t_vec origin, const t_vec dir, const t_obj *s, float *t)
{
	const t_vec	oc = vec_sub(origin, s->pos);
	const float	a = vec_dot(&dir, &dir);
	const float	b = 2.0 * (vec_dot(&dir, &oc));
	const float	c = vec_dot(&oc, &oc) - s->radius * s->radius;
	const float	delta = b * b - (4 * a * c);

	if (delta < 0.001)
		return (0);
	float t0 = (-b - sqrt(delta)) / (2 * a);
	float t1 = (-b + sqrt(delta)) / (2 * a);
	if (t0 > 0.001)
		*t = t0;
	else if (t1 > 0.001)
		*t = t1;
	else
		return (0);
	return (1);
}

t_bool	ray_hit_plane(const t_vec origin, const t_vec dir, const t_obj *p, float *t)
{
	const t_vec	po = vec_sub(p->pos, origin);
	const float	num = vec_dot(&po, &p->dir);
	const float	den = vec_dot(&dir, &p->dir);

	if (num == 0 || den == 0)
		return (0);
	*t = num / den;
	if (*t < 0)
		return (0);
	return (1);
}

t_bool ray_hit_cylinder(const t_ray *r, const t_obj *c)
{
	(void)r;
	(void)c;
	return (0);
}
