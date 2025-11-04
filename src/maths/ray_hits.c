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

t_bool	ray_hit_sphere(const t_ray *r, const t_sphere *s, float *t)
{
	const t_vec	oc = vec_sub(r->origin, s->center);
	const float	a = vec_dot(&r->dir, &r->dir);
	const float	b = 2.0 * (vec_dot(&r->dir, &oc));
	const float	c = vec_dot(&oc, &oc) - ft_pow(s->radius, 2);
	const float	delta = ft_pow(b, 2) - (4 * a * c);

	if (delta < 0)
		return (0);
	*t = (-b - ft_sqrt(delta)) / (2 * a);
	return (1);
}

// t_bool	ray_hit_plane()
