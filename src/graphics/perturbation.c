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

float sample_height(t_tex *tex, float u, float v)
{
    int x = (int)(u * tex->w) % tex->w;
    int y = (int)(v * tex->h) % tex->h;
    if (x < 0) x += tex->w;
    if (y < 0) y += tex->h;
    unsigned int color = get_tex_pixel(tex, x, y);
    float r = ((color >> 16) & 0xFF) / 255.0;
    float g = ((color >> 8) & 0xFF) / 255.0;
    float b = (color & 0xFF) / 255.0;

    // luminance standard? (perception humaine)
    //return (0.299*r + 0.587*g + 0.114*b);
    return (r/100+g/100+b/100);
}

void apply_bump_from_height(t_hit *h, t_tex *tex, float strength)
{
    const float eps_u = 1.0 / (float)fmax(1, tex->w);
    const float eps_v = 1.0 / (float)fmax(1, tex->h);
    compute_tangent_space(h);
    float u = h->uv.x;
    float v = h->uv.y;
    float h_m = sample_height(tex, u, v);
    float h_u = sample_height(tex, u + eps_u, v);
    float h_v = sample_height(tex, u, v + eps_v);
    float dhdu = (h_u - h_m) / eps_u;
    float dhdv = (h_v - h_m) / eps_v;
    t_vec n_tangent = {-strength * dhdu, -strength * dhdv, 1.0};
    n_tangent = vec_norm(n_tangent);
    t_vec pert = vec_sum(
        vec_sum(
            vec_scal(h->tangent, n_tangent.x),
            vec_scal(h->bitangent, n_tangent.y)
        ),
        vec_scal(h->normal, n_tangent.z)
    );
    h->normal = vec_norm(pert);
}

void apply_procedural_bump(t_hit *h, float strength)
{
    compute_tangent_space(h);
    float u = h->uv.x, v = h->uv.y;
    const float eps = 0.001;
    float hm = noise(u, v);
    float hu = noise(u + eps, v);
    float hv = noise(u, v + eps);
    float dhdu = (hu - hm) / eps;
    float dhdv = (hv - hm) / eps;
    t_vec n_t = vec_norm((t_vec){ -strength * dhdu, -strength * dhdv, 1.0 });
    t_vec pert = vec_sum(vec_sum(vec_scal(h->tangent, n_t.x),
                                vec_scal(h->bitangent, n_t.y)),
                         vec_scal(h->normal, n_t.z));
    h->normal = vec_norm(pert);
}

// t_vec compute_gradient(float u, float v)
// {
//     const float eps = 0.001;

//     float du = noise(u + eps, v) - noise(u - eps, v);
//     float dv = noise(u, v + eps) - noise(u, v - eps);
//     return ((t_vec){du, dv, 0});
// }

// void apply_perturbation(t_vec *normal, float u, float v)
// {
// 	const float strength = 0.8;

//     t_vec grad = compute_gradient(u, v);
//     vec_inorm(&grad);
//     t_vec perturbed = vec_sum(*normal, vec_scal(grad, strength));
//     *normal = vec_norm(perturbed);
// }

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
