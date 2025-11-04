/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:31:38 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/04 17:06:48 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_color	ray_viewport(t_ray *r, t_scene *s)
{
	const t_sphere	s1 = (t_sphere){(t_vec){500, 0, 10}, 10, \
		(t_color){255, 0, 0}};
	const t_sphere	s2 = (t_sphere){(t_vec){0, 500, 10}, 10, \
		(t_color){0, 128, 255}};
	const t_plane	p1 = (t_plane){(t_vec){1000, 1, 0}, \
		(t_vec){1, 0, 1}, (t_color){0, 255, 0}};
	const t_plane	p2 = (t_plane){(t_vec){-1000, 1, 0}, \
		(t_vec){1, 0, 1}, (t_color){128, 0, 128}};

	if (ray_hit_sphere(r, &s1))
		return (s1.color);
	if (ray_hit_sphere(r, &s2))
		return (s2.color);
	if (ray_hit_plane(r, &p1))
		return (p1.color);
	if (ray_hit_plane(r, &p2))
		return (p2.color);
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
			// vec_print(&r.dir);
			c = ray_viewport(&r, s);
			window_draw_pixel(w, x, y, color_int(&c));
			x += 1;
		}
		y += 1;
	}
}
