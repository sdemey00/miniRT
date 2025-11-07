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

static float	lights_intensity(t_scene *s, t_vec hit_point, t_vec normal, t_ray *r)
{
	float	i;
	t_idx	idx;
	t_vec	light_dir;
	t_obj	*shadow_obj;

	i = 0.0;
	idx = 0;
	if (s->ambiant.set == 1)
		i += s->ambiant.intensity;
	while (idx < s->lights_len)
	{
		light_dir = vec_sub(s->lights[idx].pos, hit_point); //rebont
		light_dir = vec_norm(&light_dir);

		//shadow
		float	shadow_t = INFINITY;
		shadow_obj = get_closest_hit(hit_point, light_dir, &shadow_t, s); //decaler le hit_point sinon il retouche l'objet direct ?
		if (shadow_obj != NULL)
		{
			idx++;
			continue ; //ombre
		}

		//diffuse
		float n_dot_l = vec_dot(&normal, &light_dir);
		if (n_dot_l > 0)
			i += s->lights[idx].intensity * n_dot_l;

		//specular
		t_vec reflect_dir = vec_sub(vec_scal(normal, 2 * vec_dot(&normal, &light_dir)), light_dir);
		t_vec view_dir = vec_scal(r->dir, -1); // redir vers caméra
		float spec_angle = fmaxf(vec_dot(&reflect_dir, &view_dir), 0.0); //get max float
		i += s->lights[idx].intensity * ft_pow(spec_angle, 32);

		idx++;
	}
	if (i > 1.0)
		i = 1.0;
	return (i);
}

t_color	ray_light_color(t_scene *s, t_ray *r, t_obj *hit_obj, float closest_t)
{
	t_vec	surface_normal;
	t_vec	hit_point;
	t_vec	tmp;

	hit_point = vec_sum(r->origin, vec_scal(r->dir, closest_t));
	if (hit_obj->e_type == SPHERE)
	{
		tmp = vec_sub(hit_point, hit_obj->pos);
		surface_normal = vec_norm(&tmp);
	}
	else if (hit_obj->e_type == PLANE)
		surface_normal = vec_norm(&hit_obj->dir);
	else
		surface_normal = (t_vec){0, 1, 0};
	float intensity = lights_intensity(s, hit_point, surface_normal, r);
	return ((t_color){hit_obj->color.x * intensity, hit_obj->color.y * intensity, hit_obj->color.z * intensity});
}
