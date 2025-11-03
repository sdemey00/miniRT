/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:16:11 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/03 19:04:49 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	ray_sphere(const t_ray *r, const t_sphere *s)
{
	const t_vec	oc = vec_sub(r->origin, s->center);
	const float	a = vec_dot(&r->dir, &r->dir);
	const float	b = 2.0 * (vec_dot(&r->dir, &oc));
	const float	c = vec_dot(&oc, &oc) - ft_pow(s->diameter / 2.0, 2);
	const float delta = ft_pow(b, 2) - (4 * a * c);
	const float	d = -b + ft_sqrt(delta) / (2 * a);
	(void)d;
	return (delta >= 0);
}
