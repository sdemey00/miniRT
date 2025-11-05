/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:06:09 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/01 16:55:17 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	window_init(t_window *w)
{
	w->mlx = mlx_init();
	if (!w->mlx)
		return (0);
	w->win = mlx_new_window(w->mlx, WIDTH, HEIGHT, "miniRT");
	if (!w->win)
		return (ft_free(w->mlx, 0));
	w->img.ptr = mlx_new_image(w->mlx, WIDTH, HEIGHT);
	w->img.address = mlx_get_data_addr(w->img.ptr, &w->img.bits_per_pixel, \
		&w->img.size_line, &w->img.endian);
	if (!w->img.address)
		return (window_free(w));
	return (1);
}

t_bool	window_free(t_window *w)
{
	mlx_destroy_image(w->mlx, w->img.ptr);
	if (w->mlx && w->win)
	{
		mlx_destroy_window(w->mlx, w->win);
		w->win = 0;
	}
	if (w->mlx)
	{
		mlx_destroy_display(w->mlx);
		free(w->mlx);
		w->mlx = 0;
	}
	return (0);
}

void	window_draw(t_window *w, t_scene *s)
{
	(void)s;
	//raytracing(w, s);
	mlx_put_image_to_window(w->mlx, w->win, w->img.ptr, 0, 0);
}

void	window_draw_pixel(t_window *w, t_uint x, t_uint y, int color)
{
	char	*dst;

	if (WIDTH <= x || HEIGHT <= y)
		return ;
	dst = w->img.address + (y * w->img.size_line + \
		x * (w->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	window_close(void *window)
{
	t_window	*w;

	w = (t_window *)window;
	window_free(w);
	exit(0);
}
