/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:31:38 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/04 17:59:50 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_color	ray_viewport(t_ray *r, t_scene *s)
{
	const t_sphere	sphere = (t_sphere){(t_vec){500, 100, 0}, 10, \
		(t_color){0, 128, 255}};
	const t_plane	plane = (t_plane){(t_vec){0, 0, 0}, \
		(t_vec){1, 1, 1}, (t_color){128, 0, 128}};

	(void)s;
	t_idx	best = 0;
	float	best_distance = INFINITY;
	float	distance = -1;
	
	if (ray_hit_sphere(r, &sphere, &distance) && distance < best_distance)
	{
		best = 1;
		best_distance = distance;
	}
	if (ray_hit_plane(r, &plane, &distance) && distance < best_distance)
	{
		best = 2;
		best_distance = distance;
	}
	if (best == 1)
		return (sphere.color);
	if (best == 2)
		return (plane.color);
	return ((t_color){160, 240, 255});
}

void	raytracing(t_window *w, t_scene *s)
{
	t_idx	x;
	t_idx	y;
	t_ray	r;
	t_color	c;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			r = (t_ray){(t_vec){x - (WIDTH / 2.0), y - (HEIGHT / 2.0), 0}, \
				(t_vec){x - (WIDTH / 2.0), y - (HEIGHT / 2.0), 1}};
			c = ray_viewport(&r, s);
			window_draw_pixel(w, x, y, color_int(&c));
			x += 1;
		}
		y += 1;
	}
}
