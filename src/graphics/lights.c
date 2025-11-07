#include "minirt.h"

//P = O + closest_t * D  // Compute intersection
//N = P - closest_sphere.center  // Compute sphere normal at intersection
//N = N / length(N)
//return closest_sphere.color * ComputeLighting(P, N)

//specular reflection
//R = 2 * N * dot(N, L) - L
//r_dot_v = dot(R, V)
//if r_dot_v > 0 {
//i += light.intensity * pow(r_dot_v/(length(R) * length(V)), s)

static float	lights_intensity(t_scene *s, t_vec P, t_vec N)
{
	float	i;
	t_idx	j;
	t_vec	light_dir;

	i = 0.0;
	j = 0.0;
	if (s->ambiant.set == 1)
		i += s->ambiant.intensity;
	while (j < s->lights_len)
	{
		// if (light.type == point)
		light_dir = vec_sub(s->lights[j].pos, P);
		light_dir = vec_norm(&light_dir);

		//if (light.type == directionnal
		// light_dir = s->lights[j].dir; //no dir for now

		// 	BROKEN
		//shadow
		// t_obj	*shadow_obj;
		// float	shadow_t;
		// shadow_obj get_closest_hit(P, light_dir, &shadow_t, s);
		// if (shadow_obj != NULL)
		// 	continue ;

		//diffuse
		float n_dot_l = vec_dot(&N, &light_dir);
		if (n_dot_l > 0)
			i += s->lights[j].intensity * n_dot_l;

		// SEMI BROKEN
		//specular
		// t_vec R = vec_scal(vec_scal(N, 2), vec_dot(&N, &light_dir));
		// float r_dot_v = vec_dot(&R, &light_dir);
		// if (r_dot_v > 0)
		// 	i += s->lights[j].intensity * ft_pow(r_dot_v, 2);
		//
		j++;
	}
	if (i > 1.0)
		i = 1.0;
	return (i);
}

t_color	ray_light_color(t_scene *s, t_ray *r, t_obj *hit_obj, float closest_t)
{
	t_vec	N;
	t_vec	P;
	t_vec	tmp;

	P = vec_sum(r->origin, vec_scal(r->dir, closest_t));
	if (hit_obj->e_type == SPHERE)
	{
		tmp = vec_sub(P, hit_obj->pos);
		N = vec_norm(&tmp);
	}
	else if (hit_obj->e_type == PLANE)
		N = vec_norm(&hit_obj->dir);
	else
		N = (t_vec){0, 1, 0};
	float intensity = lights_intensity(s, P, N);
	return ((t_color){hit_obj->color.x * intensity, hit_obj->color.y * intensity, hit_obj->color.z * intensity});
}
