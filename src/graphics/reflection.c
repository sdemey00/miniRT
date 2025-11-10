#include "minirt.h"

t_vec	get_surface_normal(t_obj *obj, t_vec hit_point)
{
	t_vec	normal;
	t_vec	tmp;

	if (obj->e_type == SPH)
	{
		tmp = vec_sub(hit_point, obj->pos);
		normal = vec_norm(tmp);
	}
	else if (obj->e_type == PLA)
		normal = vec_norm(obj->dir);
	else if (obj->e_type == CYL)
	{
		tmp = (t_vec){hit_point.x - obj->pos.x, 0, hit_point.z - obj->pos.z};
		normal = vec_norm(tmp);
	}
	else
		normal = (t_vec){0, 1, 0};
	return (normal);
}

t_color	compute_reflection(t_ray *r, t_scene *s, float closest_t, t_obj *hit_obj, int depth)
{
	t_vec	hit_point;
	t_vec	normal;
	t_vec	reflect_dir;
	t_vec	hit_point_offset;
	t_ray	reflect_ray;

	hit_point = vec_sum(r->origin, vec_scal(r->dir, closest_t));
	normal = get_surface_normal(hit_obj, hit_point);
	reflect_dir = vec_sub(r->dir, vec_scal(normal, 2 * vec_dot(r->dir, normal)));
	reflect_dir = vec_norm(reflect_dir);
	hit_point_offset = vec_sum(hit_point, vec_scal(normal, EPSILON));
	reflect_ray = (t_ray){hit_point_offset, reflect_dir};
	return (ray_color(&reflect_ray, s, depth + 1));
}
