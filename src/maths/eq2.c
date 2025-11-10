/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eq2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:28:08 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/10 17:59:34 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_eq2	eq2_init(const t_vec oc, const t_vec rdir, const float r)
{
	t_eq2	e;

	e.a = vec_dot(rdir, rdir);
	e.b = 2.0 * vec_dot(rdir, oc);
	e.c = vec_dot(oc, oc) - (r * r);
	e.d = e.b * e.b - (4 * e.a * e.c);
	e.t[0] = INFINITY;
	e.t[1] = INFINITY;
	if (e.a == 0 || e.d < 0)
		return (e);
	e.t[0] = (-e.b - ft_sqrt(e.d)) / (2 * e.a);
	e.t[1] = (-e.b + ft_sqrt(e.d)) / (2 * e.a);
	if (e.t[0] <= EPSILON)
		e.t[0] = INFINITY;
	if (e.t[1] <= EPSILON)
		e.t[1] = INFINITY;
	return (e);
}

void	eq2_set(t_eq2 *e)
{
	e->d = e->b * e->b - (4 * e->a * e->c);
	e->t[0] = INFINITY;
	e->t[1] = INFINITY;
	if (e->a == 0 || e->d < 0)
		return ;
	e->t[0] = (-e->b - ft_sqrt(e->d)) / (2 * e->a);
	e->t[1] = (-e->b + ft_sqrt(e->d)) / (2 * e->a);
	if (e->t[0] <= EPSILON)
		e->t[0] = INFINITY;
	if (e->t[1] <= EPSILON)
		e->t[1] = INFINITY;
}
