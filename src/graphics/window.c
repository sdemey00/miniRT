/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:06:09 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/06 15:24:35 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	window_init(struct s_ctx *c)
{
	c->w.win = mlx_new_window(c->w.mlx, WIDTH, HEIGHT, "miniRT");
	if (!c->w.win)
		return (ft_free(c->w.mlx, 0));
	c->w.img.ptr = mlx_new_image(c->w.mlx, WIDTH, HEIGHT);
	c->w.img.address = mlx_get_data_addr(c->w.img.ptr, &c->w.img.bits_per_pixel,
			&c->w.img.size_line, &c->w.img.endian);
	c->w.fd_controller = open("/dev/input/js0", O_RDONLY);
	if (!c->w.img.address)
		return (window_free(c));
	return (1);
}

t_bool	window_free(struct s_ctx *c)
{
	textures_free(&c->w, &c->s);
	if (c->w.img.ptr)
		mlx_destroy_image(c->w.mlx, c->w.img.ptr);
	if (c->w.mlx && c->w.win)
	{
		mlx_destroy_window(c->w.mlx, c->w.win);
		c->w.win = 0;
	}
	if (c->w.mlx)
	{
		mlx_destroy_display(c->w.mlx);
		free(c->w.mlx);
		c->w.mlx = 0;
	}
	if (c->w.fd_controller >= 0)
		close(c->w.fd_controller);
	return (0);
}

void	window_draw(struct s_ctx *c)
{
	c->state = NONE;
	blurtracing(&c->w, &c->s);
	mlx_put_image_to_window(c->w.mlx, c->w.win, c->w.img.ptr, 0, 0);
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

void	window_clear(t_window *w)
{
	ft_bzero(w->img.address, HEIGHT * w->img.size_line);
	mlx_put_image_to_window(w->mlx, w->win, w->img.ptr, 0, 0);
}
