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

static t_color	compute_diffuse(t_vec normal, t_light light, t_vec light_dir)
{
	float	n_dot_l;

	n_dot_l = vec_dot(normal, light_dir);
	if (n_dot_l <= 0)
		return ((t_color){0, 0, 0});
	return (vec_scal(light.light_norm, n_dot_l * light.intensity));
}

static t_color	compute_specular(t_vec normal, t_light light,
		t_vec light_dir, t_ray *ray)
{
	t_vec	reflect_dir;
	t_vec	view_dir;
	float	spec_angle;

	reflect_dir = vec_sub(vec_scal(normal, 2 * vec_dot(normal, light_dir)),
			light_dir);
	reflect_dir = vec_norm(reflect_dir);
	view_dir = vec_scal(ray->dir, -1);
	spec_angle = fmaxf(vec_dot(reflect_dir, view_dir), 0.0);
	spec_angle = ft_pow(spec_angle, 32); //exponant = hit_obj.shininess
	return (vec_scal(light.light_norm, spec_angle * light.intensity));
}

t_color	compute_lights(t_scene *s, t_hit *hitten, t_ray *r)
{
	t_color	i;
	t_idx	idx;
	t_vec	light_dir;
	t_color	diffuse;
	t_color	specular;

	idx = 0;
	i = compute_ambiant(s->ambiant);
	while (idx < s->lights_len)
	{
		if (is_in_shadow(s, hitten->point, hitten->normal, s->lights[idx]))
		{
			idx++;
			continue ;
		}
		light_dir = vec_norm(vec_sub(s->lights[idx].pos, hitten->point));
		diffuse = compute_diffuse(hitten->normal, s->lights[idx], light_dir);
		specular = compute_specular(hitten->normal, s->lights[idx], light_dir, \
			r);
		i = vec_sum(i, vec_sum(diffuse, specular));
		idx++;
	}
	vec_fmin((t_vec *)&i, 1.0);
	return (i);
}
