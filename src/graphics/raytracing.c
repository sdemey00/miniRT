/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:31:38 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/10 15:47:16 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	draw_grid(t_window *w, const t_idx c[2], int color, \
	const t_suint ppp)
{
	t_idx	i;
	t_idx	j;

	j = 0;
	while (j <= ppp)
	{
		i = 0;
		while (i <= ppp)
		{
			window_draw_pixel(w, c[0] + i, c[1] + j, color);
			i++;
		}
		j++;
	}
}

void	blurtracing(t_window *w, t_scene *s)
{
	const t_suint	ppp = 15;
	t_idx			i;
	t_idx			j;
	t_color			c;
	t_ray			r;

	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			r = camera_ray(&s->camera, i, j);
			c = ray_color(&r, s);
			draw_grid(w, (const t_idx[2]){i, j}, color_int(&c), ppp);
			i += ppp;
		}
		j += ppp;
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
