/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:31:38 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/12 15:19:36 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	draw_grid(t_window *w, const t_idx c[2], int color, \
	const t_suint blur)
{
	t_idx	i;
	t_idx	j;

	j = 0;
	while (j <= blur)
	{
		i = 0;
		while (i <= blur)
		{
			window_draw_pixel(w, c[0] + i, c[1] + j, color);
			i++;
		}
		j++;
	}
}

void	raytracing(t_window *w, t_scene *s, const t_suint blur)
{
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
			c = ray_color(&r, s, 0);
			draw_grid(w, (const t_idx[2]){i, j}, color_int(&c), blur);
			i += blur;
		}
		j += blur;
	}
}

void	full_render(struct s_ctx *c)
{
	const t_ssuint	temp_blur = c->s.blur;

	c->rendering = 1;
	c->s.blur = 1;
	ft_printf("Rendering ...");
	window_draw(&c->w, &c->s);
	c->s.blur = temp_blur;
	ft_printf("\n");
}
