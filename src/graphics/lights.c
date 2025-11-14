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

static t_color	compute_diffuse(t_light *light)
{
	if (light->ndotl <= 0)
		return ((t_color){0, 0, 0});
	return (vec_scal(light->norm, light->ndotl * light->intensity));
}

static t_color	compute_specular(t_hit *hitten, t_light *light, t_ray *ray)
{
	t_vec	r_dir;
	t_vec	view_dir;
	float	spec_angle;

	r_dir = vec_sub(vec_scal(hitten->normal, 2 * light->ndotl), light->dir);
	r_dir = vec_norm(r_dir);
	view_dir = vec_scal(ray->dir, -1);
	spec_angle = fmaxf(vec_dot(r_dir, view_dir), 0.0);
	if (hitten->obj->shininess < 8)
		hitten->obj->shininess = 8;
	spec_angle = ft_pow(spec_angle, hitten->obj->shininess);
	return (vec_scal(light->norm, spec_angle * light->intensity));
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
		if (!is_in_shadow(s, hitten->point, hitten->normal, s->lights[idx]))
		{
			delta = vec_sub(s->lights[idx].pos, hitten->point);
			s->lights[idx].dir = vec_norm(delta);
			s->lights[idx].ndotl = vec_dot(hitten->normal, s->lights[idx].dir);
			diffuse = compute_diffuse(&s->lights[idx]);
			specular = compute_specular(hitten, &s->lights[idx], r);
			i = vec_sum(i, vec_sum(diffuse, specular));
		}
		idx++;
	}
	return (i);
}
