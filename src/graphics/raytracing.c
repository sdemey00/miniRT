/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:31:38 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/03 19:17:07 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_color	ray_viewport(t_ray *r, t_scene *s)
{
	(void)s;
	t_sphere sphere = (t_sphere){(t_vec){100, 200, 1000}, 0, (t_color){255, 0, 0}};
	if (ray_sphere(r, &sphere) > 0)
		return (sphere.color);
	return (t_color){160, 240, 255};
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
			r = (t_ray){(t_vec){x - (WIDTH / 2.0), y - (HEIGHT / 2.0), 0}, (t_vec){x - (WIDTH / 2.0), y - (HEIGHT / 2.0), 1}};
			c = ray_viewport(&r, s);
			window_draw_pixel(w, x, y, color_int(&c));
			x += 1;
		}
		y += 1;
	}
}
