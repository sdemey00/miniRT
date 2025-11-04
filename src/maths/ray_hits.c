/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_hits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:16:11 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/04 14:25:18 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	ray_hit_sphere(const t_ray *r, const t_sphere *s)
{
	const t_vec	oc = vec_sub(r->origin, s->center);
	const float	a = vec_dot(&r->dir, &r->dir);
	const float	b = 2.0 * (vec_dot(&r->dir, &oc));
	const float	c = vec_dot(&oc, &oc) - s->radius*s->radius;
	const float	delta = b*b - (4 * a * c);

    if (delta < 0) 
		return 0;
    float t0 = (-b - sqrt(delta)) / (2*a);
    float t1 = (-b + sqrt(delta)) / (2*a);
    if (t0 > 0) 
		return 1;
    if (t1 > 0)
		return 1;
    return 0;
}
// t_bool	ray_hit_plane()
