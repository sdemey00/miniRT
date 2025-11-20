/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemey <sdemey@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:34:18 by sdemey            #+#    #+#             */
/*   Updated: 2025/11/10 14:34:19 by sdemey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_color	compute_ambiant(t_ambiant a)
{
	t_color	a_norm;

	if (!a.set)
		return ((t_color){0, 0, 0});
	a_norm = vec_rscal(a.color, 255.0);
	return (vec_scal(a_norm, a.intensity));
}

static t_color	compute_diffuse(t_scene *s, t_hit *hitten, t_light *light)
{
	if (!bitmap_get(&s->effects, DIFFUSE_LIGHT)
		|| !bitmap_get(&hitten->obj->effects, DIFFUSE_LIGHT))
		return ((t_color){0, 0, 0});
	if (light->ndotl <= 0)
		return ((t_color){0, 0, 0});
	return (vec_scal(light->norm, light->ndotl * light->intensity));
}

static t_color	compute_specular(t_scene *s, t_hit *hitten,
		t_light *light, t_ray *ray)
{
	t_vec	r_dir;
	t_vec	view_dir;
	float	spec_angle;

	if (!bitmap_get(&s->effects, SPECULAR_LIGHT)
		|| !bitmap_get(&hitten->obj->effects, SPECULAR_LIGHT))
		return ((t_color){0, 0, 0});
	r_dir = vec_sub(vec_scal(hitten->normal, 2 * light->ndotl), light->dir);
	r_dir = vec_norm(r_dir);
	view_dir = vec_scal(ray->dir, -1);
	spec_angle = fmaxf(vec_dot(r_dir, view_dir), 0.0);
	if (hitten->obj->shininess < 8)
		hitten->obj->shininess = 8;
	spec_angle = ft_pow(spec_angle, hitten->obj->shininess);
	return (vec_scal(light->norm, spec_angle * light->intensity));
}

static t_bool	is_in_shadow(t_scene *s, t_hit *hitten, t_light *light)
{
	t_ray	shadow_ray;
	t_hit	shadow_hit;
	float	light_dist;

	shadow_ray = (t_ray){hitten->p_offset, light->dir};
	shadow_hit = get_closest_hit(&shadow_ray, s);
	light_dist = vec_mag(vec_sub(light->pos, hitten->p_offset));
	if (shadow_hit.obj && shadow_hit.dist > EPSILON && shadow_hit.dist < \
		light_dist)
		return (1);
	return (0);
}

t_color	compute_lights(t_scene *s, t_hit *hitten, t_ray *r)
{
	t_color	i;
	t_idx	idx;
	t_color	diffuse;
	t_color	specular;
	t_vec	delta;

	idx = 0;
	i = compute_ambiant(s->ambiant);
	while (idx < s->lights_len)
	{
		delta = vec_sub(s->lights[idx].pos, hitten->point);
		s->lights[idx].dir = vec_norm(delta);
		if (!bitmap_get(&s->effects, SHADOWS)
			|| !bitmap_get(&hitten->obj->effects, SHADOWS)
			|| !is_in_shadow(s, hitten, &s->lights[idx]))
		{
			s->lights[idx].ndotl = vec_dot(hitten->normal, s->lights[idx].dir);
			diffuse = compute_diffuse(s, hitten, &s->lights[idx]);
			specular = compute_specular(s, hitten, &s->lights[idx], r);
			i = vec_sum(i, vec_sum(diffuse, specular));
		}
		idx++;
	}
	return (i);
}
