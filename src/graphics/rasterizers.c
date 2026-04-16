/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rasterizers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:26:33 by mmichele          #+#    #+#             */
/*   Updated: 2026/04/16 18:32:22 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "threading.h"

static void	draw_thread_pixel(t_thread_ctx *t, t_idx x, t_idx y, t_color *c)
{
	pthread_mutex_lock(t->mtx);
	mlx_pixel_put(t->w->mlx, t->w->win, x, y, color_int(c));
	pthread_mutex_unlock(t->mtx);
}

void*	raster_linear(void *ctx)
{
	t_thread_ctx	*t = (t_thread_ctx *)ctx;
	const t_uint	offset = ceil(t->s.blur / 2.0);
	t_idx			i;
	t_idx			j;
	t_color			c;
	t_ray			r;

	j = t->id;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			if (!((i % t->s.blur) - offset == 0 && (j % t->s.blur) - offset == 0))
			{
				r = camera_ray(&t->s.camera, i, j);
				c = vec_scal(ray_color(&r, &t->s, 0), 255);
				draw_thread_pixel(t, i, j, &c);
			}
			i++;
		}
		j += RENDER_THREADS;
	}
	return (0);
}

void*	raster_evenly(void *ctx)
{
	t_thread_ctx	*t = (t_thread_ctx *)ctx;
	const t_uint	pixel_count = WIDTH * HEIGHT;
	t_idx			i[3];
	t_color			c;
	t_ray			r;
	t_uint			count;

	count = t->id;
	while (count < pixel_count)
	{
		i[2] = (count * 11 + 1) % pixel_count;
		i[0] = i[2] % WIDTH;
		i[1] = i[2] / WIDTH;
		r = camera_ray(&t->s.camera, i[0], i[1]);
		c = vec_scal(ray_color(&r, &t->s, 0), 255);
		draw_thread_pixel(t, i[0], i[1], &c);
		count += RENDER_THREADS;
	}
	return (0);
}

void*	raster_grid(void *ctx)
{
	t_thread_ctx	*t = (t_thread_ctx *)ctx;
	const t_uint	step = 5;
	t_idx			i[2];
	t_color			c;
	t_ray			r;
	t_uint			k;

	k = step;
	while (k)
	{
		i[1] = t->id * k;
		while (i[1] < HEIGHT)
		{
			i[0] = 0;
			while (i[0] < WIDTH)
			{
				r = camera_ray(&t->s.camera, i[0], i[1]);
				c = vec_scal(ray_color(&r, &t->s, 0), 255);
				draw_thread_pixel(t, i[0], i[1], &c);
				i[0] += k;
			}
			i[1] += k * RENDER_THREADS;
		}
		k--;
	}
	return (0);
}
