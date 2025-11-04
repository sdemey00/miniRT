/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:31:38 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/04 14:25:03 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_ray get_ray(int i, int j, double fov) 
{
    double aspect = (double)WIDTH / HEIGHT;
    double x = (2 * ((i + 0.5) / WIDTH) - 1) * aspect * tan(fov * FT_PI / 180 / 2);
    double y = (1 - 2 * ((j + 0.5) / HEIGHT)) * tan(fov * FT_PI / 180 / 2);
	t_vec norm_dir = (t_vec){x, y, -1};
    t_vec dir = vec_norm(&norm_dir);
    return ((t_ray){(t_vec){0,0,0}, dir});
}

t_color ray_color(t_ray r) 
{
    t_sphere sphere = {(t_vec){0,0,-5}, 1, {255,0,0}};
    if (ray_hit_sphere(&r, &sphere))
        return (sphere.color);
    return (t_color){135,206,235}; // fond bleu ciel
}

// static t_color	ray_viewport(t_ray *r, t_scene *s)
// {
// 	const t_sphere	sphere = (t_sphere){(t_vec){500, 100, 0}, 10, 
// 		(t_color){0, 128, 255}};
// 	const t_plane	plane = (t_plane){(t_vec){0, 0, 0}, 
// 		(t_vec){1, 1, 1}, (t_color){128, 0, 128}};

// 	(void)s;
// 	t_idx	best = 0;
// 	float	best_distance = INFINITY;
// 	float	distance = -1;
	
// 	if (ray_hit_sphere(r, &sphere, &distance) && distance < best_distance)
// 	{
// 		best = 1;
// 		best_distance = distance;
// 	}
// 	if (ray_hit_plane(r, &plane, &distance) && distance < best_distance)
// 	{
// 		best = 2;
// 		best_distance = distance;
// 	}
// 	if (best == 1)
// 		return (sphere.color);
// 	if (best == 2)
// 		return (plane.color);
// 	return ((t_color){160, 240, 255});
// }

void	raytracing(t_window *w, t_scene *s)
{
	t_idx	x;
	t_idx	y;
	t_ray	r;
	t_color	c;
	(void)s;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			r = get_ray(x , y , 70);
			c = ray_color(r);
			window_draw_pixel(w, x, y, color_int(&c));
			x += 1;
		}
		y += 1;
	}
}
