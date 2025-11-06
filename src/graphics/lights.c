#include "minirt.h"

//P = O + closest_t * D  // Compute intersection
//N = P - closest_sphere.center  // Compute sphere normal at intersection
//N = N / length(N)
//return closest_sphere.color * ComputeLighting(P, N)


static float	lights_intensity(t_scene *s, t_vec P, t_vec N)
{
	float	i = 0.0;
	t_idx	j = 0;

	if (s->ambiant.set == 1)
		i += s->ambiant.intensity;
	while (j < s->lights_len)
	{
		t_light *L = &s->lights[j];
		t_vec	light_dir;
		light_dir = vec_sub(L->pos, P);
		light_dir = vec_norm(&light_dir);
		float n_dot_l = vec_dot(&N, &light_dir);
		if (n_dot_l > 0)
			i += L->intensity * n_dot_l;
		j++;
	}
	if (i > 1.0)
		i = 1.0;
	return (i);
}

t_color	ray_light_color(t_scene *s, t_ray *r, t_obj *hit_obj, float closest_t)
{
	t_vec N;
	t_vec P;

	P = vec_sum(r->origin, vec_scal(r->dir, closest_t));
	if (hit_obj->e_type == SPHERE)
	{
		t_vec tmp = vec_sub(P, hit_obj->pos);
		N = vec_norm(&tmp);
	}
	else if (hit_obj->e_type == PLANE)
		N = vec_norm(&hit_obj->dir);
	else
		N = (t_vec){0, 1, 0};

	float intensity = lights_intensity(s, P, N);

	return ((t_color){hit_obj->color.x * intensity, hit_obj->color.y * intensity, hit_obj->color.z * intensity});
}
