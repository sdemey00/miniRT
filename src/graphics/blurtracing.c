/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:31:38 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/21 14:02:20 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	draw_grid(t_window *w, const t_idx c[2], int color, \
	const t_suint blur)
{
	const int	start = -ceil(blur / 2.0);
	const int	stop = blur / 2.0;
	t_ridx		i;
	t_ridx		j;

	j = start;
	while (j < HEIGHT && j <= stop)
	{
		i = start;
		while (i < WIDTH && i <= stop)
		{
			window_draw_pixel(w, c[0] + i, c[1] + j, color);
			i++;
		}
		j++;
	}
}

static void	draw_reticle(t_window *w)
{
	const unsigned int	center[2] = {WIDTH / 2, HEIGHT / 2};
	const t_color		c = (t_color){0, 255, 0};

	draw_grid(w, (const t_idx[2]){center[0] - 2, center[1] - 2}, \
		color_int(&c), 4);
}

void	blurtracing(t_window *w, t_scene *s)
{
	const t_uint	offset = ceil(s->blur / 2.0);
	t_idx			i;
	t_idx			j;
	t_color			c;
	t_ray			r;

	j = offset;
	while (j < HEIGHT + offset)
	{
		i = offset;
		while (i < WIDTH + offset)
		{
			r = camera_ray(&s->camera, i, j);
			c = vec_scal(ray_color(&r, s, 0), 255);
			draw_grid(w, (const t_idx[2]){i, j}, color_int(&c), s->blur);
			i += s->blur;
		}
		j += s->blur;
	}
	if (s->reticle && !s->controlled)
		draw_reticle(w);
}
