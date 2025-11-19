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

static float	noise(float u, float v)
{
	return (sinf(u * 15.0) * cosf(v * 15.0));
}

t_vec compute_gradient(float u, float v)
{
    const float eps = 0.001;

    float du = noise(u + eps, v) - noise(u - eps, v);
    float dv = noise(u, v + eps) - noise(u, v - eps);
    return ((t_vec){du, dv, 0});
}

void apply_perturbation(t_vec *normal, float u, float v)
{
	const float strength = 0.8;

    t_vec grad = compute_gradient(u, v);
    vec_inorm(&grad);
    t_vec perturbed = vec_sum(*normal, vec_scal(grad, strength));
    *normal = vec_norm(perturbed);
}





// void sphere_tangent_space(t_vec p, t_vec *T, t_vec *B, t_vec *N)
// {
//     *N = vec_norm(p);
//     t_vec up = fabs(N->y) < 0.999 ? vec(0,1,0) : vec(1,0,0);
//     *T = vec_norm(vec_cross(*N, up));
//     *B = vec_cross(*N, *T);
// }
//
// void plane_tangent_space(t_vec normal, t_vec *T, t_vec *B, t_vec *N)
// {
//     *N = vec_norm(normal);
//     t_vec up = fabs(N->y) < 0.999 ? vec(0,1,0) : vec(1,0,0);
//     *T = vec_norm(vec_cross(up, *N));
//     *B = vec_cross(*N, *T);
// }
//
// void apply_bump(t_vec *normal, float u, float v, 
//                 t_vec T, t_vec B, t_vec N)
// {
//     const float eps = 0.002;
//     const float strength = 0.4;
//
//     float h0 = noise(u, v);
//     float hx = noise(u + eps, v);
//     float hy = noise(u, v + eps);
//
//     float dHdu = (hx - h0);
//     float dHdv = (hy - h0);
//
//     t_vec bump =
//         vec_sum(N,
//             vec_sum(
//                 vec_scal(T, dHdu * strength),
//                 vec_scal(B, dHdv * strength)
//             )
//         );
//
//     *normal = vec_norm(bump);
// }
//
//apply_bump(&hit_normal, u, v, T, B, N);
