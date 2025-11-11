#include "minirt.h"

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
