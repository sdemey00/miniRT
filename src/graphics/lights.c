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

// static float	lights_intensity(t_scene *s, t_vec hit_point,
// 	t_vec normal, t_ray *r)
// {
// 	float	i;
// 	t_idx	idx;
// 	t_vec	light_dir;
// 	t_obj	*shadow_obj;
// 	t_ray	new_ray;
//
// 	i = 0.0;
// 	idx = 0;
// 	if (s->ambiant.set == 1)
// 		i += s->ambiant.intensity;
// 	while (idx < s->lights_len)
// 	{
// 		light_dir = vec_sub(s->lights[idx].pos, hit_point); //rebont
// 		light_dir = vec_norm(light_dir);
//
// 		//shadow
// 		float	shadow_t = INFINITY;
// 		new_ray = (t_ray){hit_point, light_dir};
// 		shadow_obj = get_closest_hit(&new_ray, &shadow_t, s); //decaler le hit_point sinon il retouche l'objet direct ?
// 		if (shadow_obj != NULL)
// 		{
// 			idx++;
// 			continue ; //ombre
// 		}
//
// 		//diffuse
// 		float n_dot_l = vec_dot(normal, light_dir);
// 		if (n_dot_l > 0)
// 			i += s->lights[idx].intensity * n_dot_l;
//
// 		//specular
// 		t_vec reflect_dir = vec_sub(vec_scal(normal, 2 * vec_dot(normal, light_dir)), light_dir);
// 		t_vec view_dir = vec_scal(r->dir, -1); // redir vers caméra
// 		float spec_angle = vec_dot(reflect_dir, view_dir);
// 		if (spec_angle < 0.0)
// 			spec_angle = 0.0;
// 		i += s->lights[idx].intensity * ft_pow(spec_angle, 32); //pow exponant = phong intensity
// 		idx++;
// 	}
// 	if (i > 1.0)
// 		i = 1.0;
// 	return (i);
// }


static t_color	compute_lights(t_scene *s, t_vec hit_point, t_vec normal, t_ray *r)
{
	t_color i = {0, 0, 0};
	t_idx idx = 0;

	if (s->ambiant.set)
		i = vec_scal(vec_rscal(s->ambiant.color, 255.0), s->ambiant.intensity);

	while (idx < s->lights_len)
	{
		t_light light = s->lights[idx];
		t_vec light_dir = vec_norm(vec_sub(light.pos, hit_point));

		// Shadow
		t_vec origin_offset = vec_sum(hit_point, vec_scal(normal, 1e-4));
		t_ray new_ray = {origin_offset, light_dir};
		// t_ray new_ray = {hit_point, light_dir};
		float shadow_t = INFINITY;
		t_obj *shadow_obj = get_closest_hit(&new_ray, &shadow_t, s);
		if (shadow_obj)
		{
			idx++;
			continue;
		}

		t_vec diff = {0, 0, 0};
		float n_dot_l = vec_dot(normal, light_dir);
		if (n_dot_l > 0)
			diff = vec_scal(vec_rscal(light.color, 255.0), n_dot_l * light.intensity);

		t_vec reflect_dir = vec_sub(vec_scal(normal, 2 * vec_dot(normal, light_dir)), light_dir);
		t_vec view_dir = vec_scal(r->dir, -1);
		float spec_angle = vec_dot(reflect_dir, view_dir);
		if (spec_angle < 0)
			spec_angle = 0;
		spec_angle = ft_pow(spec_angle, 32);
		t_vec spec = vec_scal(vec_rscal(light.color, 255.0), spec_angle * light.intensity);

		i = vec_sum(i, vec_sum(diff, spec));
		idx++;
	}    
	i.x = fminf(i.x, 1.0);
    i.y = fminf(i.y, 1.0);
    i.z = fminf(i.z, 1.0);
	return (i);
}

t_color	ray_light_color(t_scene *s, t_ray *r, t_obj *hit_obj, float closest_t)
{
	t_vec	surface_normal;
	t_vec	hit_point;
	t_vec	tmp;
	// float	intensity;

	hit_point = vec_sum(r->origin, vec_scal(r->dir, closest_t));
	if (hit_obj->e_type == SPH)
	{
		tmp = vec_sub(hit_point, hit_obj->pos);
		surface_normal = vec_norm(tmp);
	}
	else if (hit_obj->e_type == PLA)
		surface_normal = vec_norm(hit_obj->dir);
	else
		surface_normal = (t_vec){0, 1, 0};
	// intensity = lights_intensity(s, hit_point, surface_normal, r);
	// return (vec_scal(hit_obj->color, intensity));
	t_color light_color = compute_lights(s, hit_point, surface_normal, r);
	t_color res = (t_color){hit_obj->color.x * light_color.x, hit_obj->color.y * light_color.y, hit_obj->color.z * light_color.z};
	res.x = fminf(res.x, 255.0);
	res.y = fminf(res.y, 255.0);
	res.z = fminf(res.z, 255.0);
	return (res);
}
