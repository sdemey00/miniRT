#include "minirt.h"

//P = O + closest_t * D  // Compute intersection
//N = P - closest_sphere.center  // Compute sphere normal at intersection
//N = N / length(N)
//return closest_sphere.color * ComputeLighting(P, N)

float	compute_lights(t_scene *s, t_vec P, t_vec N)
{
	float	i = 0.0;
	t_idx	j = 0;
    t_vec L;

	if (s->ambiant.set == 1)
		i += s->ambiant.intensity;
	while (j < s->lights_len)
	{
		if (lights[j].type == POINT)
			L = vec_sub(lights[j].pos, P);
		n_dot_l = vec_dot(N, L);
		if (n_dot_l > 0)
			i += lights[j].intensity * n_dot_l / (vec_mag(N) * vec_mag(L));
		j++;
	}
	return (i);
}
