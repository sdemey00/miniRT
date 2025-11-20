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

static float	sample_height(t_tex *tex, float u, float v)
{
	int				x;
	int				y;
	t_color			rgb;
	unsigned int	color;

	x = (int)(u * tex->w) % tex->w;
	y = (int)(v * tex->h) % tex->h;
	if (x < 0)
		x += tex->w;
	if (y < 0)
		y += tex->h;
	color = get_tex_pixel(tex, x, y);
	rgb = (t_color)
	{
		((color >> 16) & 0xFF) / 255.0,
		((color >> 8) & 0xFF) / 255.0,
		(color & 0xFF) / 255.0,
	};
	return (rgb.x / 100 + rgb.y / 100 + rgb.z / 100);
}

static void	apply_texture_bump(t_hit *h, float *dhdu, float *dhdv)
{
	const float	eps_u = 1.0 / fmax(1, h->obj->texture.w);
	const float	eps_v = 1.0 / fmax(1, h->obj->texture.h);
	const float	hm = sample_height(&h->obj->texture, h->uv.x, h->uv.y);
	const float	hu = sample_height(&h->obj->texture, h->uv.x + eps_u, h->uv.y);
	const float	hv = sample_height(&h->obj->texture, h->uv.x, h->uv.y + eps_v);

	*dhdu = (hu - hm) / eps_u;
	*dhdv = (hv - hm) / eps_v;
}

static void	apply_procedural_bump(t_hit *h, float *dhdu, float *dhdv)
{
	const float	hm = noise(h->uv.x, h->uv.y);
	const float	hu = noise(h->uv.x + EPSILON, h->uv.y);
	const float	hv = noise(h->uv.x, h->uv.y + EPSILON);

	*dhdu = (hu - hm) / EPSILON;
	*dhdv = (hv - hm) / EPSILON;
}

void	apply_bump(t_hit *h, float strength)
{
	float	dhdu;
	float	dhdv;
	t_vec	n_t;
	t_vec	pert;

	compute_tangent_space(h);
	if (1 > 0) //TEXTURE_BUMP
		apply_texture_bump(h, &dhdu, &dhdv);
	else if (1 < 0) //PROCEDURAL_BUMP
		apply_procedural_bump(h, &dhdu, &dhdv);
	else
		return ;
	n_t = vec_norm((t_vec){-strength * dhdu, -strength * dhdv, 1.0});
	pert = vec_sum(vec_sum(vec_scal(h->tangent, n_t.x),
				vec_scal(h->bitangent, n_t.y)),
			vec_scal(h->normal, n_t.z));
	h->normal = vec_norm(pert);
}
