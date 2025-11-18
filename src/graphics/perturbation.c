/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perturbation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemey <sdemey@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 18:53:53 by sdemey            #+#    #+#             */
/*   Updated: 2025/11/18 18:53:56 by sdemey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static float	noise(float x, float y)
{
	return (sinf(x * 15.0) * cosf(y * 15.0));
}
//
// static float	noise(float u, float v)
// {
// 	const float	r = ft_sqrt(u * u + v * v);
// 	return (sinf(r * 40.0));
// }
//
// static float	noise(float u, float v)
// {
// 	(void)v;
//     return sinf(u * 20.0);
// }
//
// fbm ??
// 	Fractional Brownian Motion

static t_vec	compute_gradient(float u, float v)
{
	const float	hx = noise(u + EPSILON, v);
	const float	hy = noise(u, v + EPSILON);
	const float	dhdu = (hx - noise(u, v)) / EPSILON;
	const float	dhdv = (hy - noise(u, v)) / EPSILON;

	return (t_vec){dhdu, dhdv, 0.0};
}

void	apply_perturbation(t_vec *normal, float u, float v)
{
	const float strength = 0.3;
	t_vec		grad;
	t_vec		perturbed;

	grad = compute_gradient(u, v);
	perturbed = vec_sum(*normal, vec_scal(grad, strength));
	*normal = vec_norm(perturbed);
}
