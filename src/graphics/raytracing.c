/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:31:38 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/06 12:47:23 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	draw_grid(t_window *w, t_idx x, t_idx y, int color, const short unsigned int res)
{
	t_ridx	i;
	t_ridx	j;

	j = -res;
	while (j <= res)
	{
		i = -res;
		while (i <= res)
		{
			window_draw_pixel(w, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

// Use this function to show something after moving, and draw only real render
// when no key pressed after a given amount of time, or something.
void	blurtracing(t_window *w, t_scene *s)
{
	t_idx	i;
	t_idx	j;
	t_color	c;
	t_ray	r;
	const short unsigned int res = 1; // Should be at least 1

	j = (res * 2) - 1;
	while (j < HEIGHT - 1)
	{
		i = (res * 2) - 1;
		while (i < WIDTH - 1)
		{
			r = camera_ray(&s->camera, i, j);
			c = ray_color(&r, s);
			draw_grid(w, i, j, color_int(&c), res);
			i += (res * 2) + 1;
		}
		j += (res * 2) + 1;
	}
}

void	raytracing(t_window *w, t_scene *s)
{
	t_idx	i;
	t_idx	j;
	t_color	c;
	t_ray	r;

	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			r = camera_ray(&s->camera, i, j);
			c = ray_color(&r, s);
			window_draw_pixel(w, i, j, color_int(&c));
			i++;
		}
		j++;
	}
}
