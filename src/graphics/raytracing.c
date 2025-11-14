/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:31:38 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/14 12:36:02 by mmichele         ###   ########.fr       */
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

void	draw_reticle(t_window *w)
{
	const unsigned int	center[2] = {WIDTH / 2, HEIGHT / 2};
	const t_color		c = (t_color){0, 255, 0};

	draw_grid(w, (const t_idx[2]){center[0] - 2, center[1] - 2}, color_int(&c), 4);
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
			c = vec_scal(c, 255.0);
			draw_grid(w, (const t_idx[2]){i, j}, color_int(&c), blur);
			i += blur;
		}
		j += blur;
	}
	if (s->reticle && !s->controlled)
		draw_reticle(w);
}

int	full_render(struct s_ctx *c)
{
	const t_ssuint	temp_blur = c->s.blur;
	const t_bool	temp_reticle = c->s.reticle;
	double			start_time;

	c->s.reticle = 0;
	c->rendering = 1;
	c->s.blur = 1;
	ft_printf("Render");
	start_time = time_now();
	window_draw(&c->w, &c->s);
	ft_printf("ed in %.2fs\n", (time_now() - start_time) / 1000);
	c->s.blur = temp_blur;
	c->s.reticle = temp_reticle;
	return (0);
}
