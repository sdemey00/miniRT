#include "minirt.h"

//P = O + closest_t * D  // Compute intersection
//N = P - closest_sphere.center  // Compute sphere normal at intersection
//N = N / length(N)
//return closest_sphere.color * ComputeLighting(P, N)

// t_vec N;
// t_vec P;

// P = vec_sum(r->origin, vec_scal(r->dir, closest_t));
// if (hit_obj->e_type == SPHERE)
// {
// 	N = vec_norm(&vec_sub(P, hit_obj->pos));
// 	//t_vec tmp = vec_sub(P, hit_obj->pos);
// 	//N = vec_norm(&tmp);
// }
// else if (hit_obj->e_type == PLANE)
// 	N = vec_norm(&hit_obj->dir);
// else
// 	N = (t_vec){0, 1, 0};

// float intensity = compute_lights(s, P, N);

// t_color base = hit_obj->color;
// return ((t_color){base.x * intensity, base.y * intensity, base.z * intensity});

float	compute_lights(t_scene *s, t_vec P, t_vec N)
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
