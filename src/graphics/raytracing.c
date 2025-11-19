/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:31:38 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/20 00:31:38 by mmichele         ###   ########.fr       */
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

	ft_printf("%u\n", s->blur);
	unsigned int count = 0;
	j = offset;
	while (j < HEIGHT + offset - 1)
	{
		i = offset;
		while (i < WIDTH + offset - 1)
		{
			r = camera_ray(&s->camera, i, j);
			c = vec_scal(ray_color(&r, s, 0), 255);
			draw_grid(w, (const t_idx[2]){i, j}, color_int(&c), s->blur);
			count++;
			//ft_printf("i=%u j=%u\n", i, j);
			i += s->blur;
		}
		j += s->blur;
	}
	ft_printf("Shot %u rays\n", count);
	if (s->reticle && !s->controlled)
		draw_reticle(w);
}

static void	raytracing(t_window *w, t_scene *s)
{
	//const t_uint	offset = ceil(s->blur / 2.0);
	t_idx			i;
	t_idx			j;
	t_color			c;
	t_ray			r;

	unsigned int count = 0;
	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			if (1)
			{
				r = camera_ray(&s->camera, i, j);
				c = vec_scal(ray_color(&r, s, 0), 255);
				mlx_pixel_put(w->mlx, w->win, i, j, color_int(&c));
				//ft_printf("i=%u j=%u\n", i, j);
				count++;
			}
			i++;
		}
		j++;
	}
	ft_printf("Shot %u rays\n", count);
}

t_bool	full_render(struct s_ctx *c)
{
	const t_bool	temp_reticle = c->s.reticle;
	double			start_time;

	if (c->state == RENDERED)
		return (0);
	c->state = RENDERING;
	c->s.reticle = 0;
	ft_printf("Render\n");
	start_time = time_now();
	raytracing(&c->w, &c->s);
	ft_printf("ed in %.3fs\n", (time_now() - start_time) / 1000);
	c->s.reticle = temp_reticle;
	c->state = RENDERED;
	return (0);
}
