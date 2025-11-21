/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rasterizers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:26:33 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/21 17:03:03 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	raster_linear(t_window *w, t_scene*s)
{
	const t_uint	offset = ceil(s->blur / 2.0);
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
			if (!((i % s->blur) - offset == 0 && (j % s->blur) - offset == 0))
			{
				r = camera_ray(&s->camera, i, j);
				c = vec_scal(ray_color(&r, s, 0), 255);
				mlx_pixel_put(w->mlx, w->win, i, j, color_int(&c));
			}
			i++;
		}
		j++;
	}
}

void	raster_evenly(t_window *w, t_scene *s)
{
	const t_uint	k[2] = {ceil(s->blur / 2.0), WIDTH * HEIGHT};
	t_idx			i[3];
	t_color			c;
	t_ray			r;
	t_uint			count;

	window_clear(w);
	count = 0;
	while (count < k[1])
	{
		i[2] = (count * 11 + 1) % k[1];
		i[0] = i[2] % WIDTH;
		i[1] = i[2] / WIDTH;
		r = camera_ray(&s->camera, i[0], i[1]);
		c = vec_scal(ray_color(&r, s, 0), 255);
		mlx_pixel_put(w->mlx, w->win, i[0], i[1], color_int(&c));
		count++;
	}
}

void	raster_grid(t_window *w, t_scene *s)
{
	const t_uint	step = 5;
	t_idx			i[2];
	t_color			c;
	t_ray			r;
	t_uint			k;

	window_clear(w);
	k = step;
	while (k)
	{
		i[1] = 0;
		while (i[1] < HEIGHT)
		{
			i[0] = 0;
			while (i[0] < WIDTH)
			{
				r = camera_ray(&s->camera, i[0], i[1]);
				c = vec_scal(ray_color(&r, s, 0), 255);
				mlx_pixel_put(w->mlx, w->win, i[0], i[1], color_int(&c));
				i[0] += k;
			}
			i[1] += k;
		}
		k--;
	}
}
