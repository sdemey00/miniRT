/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:01:57 by sdemey            #+#    #+#             */
/*   Updated: 2025/11/20 16:26:03 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	parttracing(t_window *w, t_scene *s, const t_uint x, const t_uint y)
{
	const t_uint	offset = ceil(s->blur / 2.0);
	const t_ridx	x_range = WIDTH / 20;
	const t_ridx	y_range = HEIGHT / 20;
	t_ridx			i;
	t_ridx			j;
	t_color			c;
	t_ray			r;

	j = -y_range;
	while (j < HEIGHT && j <= y_range)
	{
		i = -x_range;
		while (i < WIDTH && i <= x_range)
		{
			if (!((i % s->blur) - offset == 0 && (j % s->blur) - offset == 0))
			{
				r = camera_ray(&s->camera, x + i, y + j);
				c = vec_scal(ray_color(&r, s, 0), 255);
				mlx_pixel_put(w->mlx, w->win, x + i, y + j, color_int(&c));
			}
			i++;
		}
		j++;
	}
}

int	mouse_press(int key, int x, int y, struct s_ctx *c)
{
	t_ray	r;
	t_color	clr;

	if (VERBOSE)
		ft_printf("Mouse pressed with key %d at %d %d\n", key, x, y);
	if (key == 1 && !c->s.controlled)
		scene_take_control(&c->s, x, y);
	else if (key == 1 && c->s.controlled)
		c->s.controlled = 0;
	else if (key == 3)
	{
		parttracing(&c->w, &c->s, x, y);
		r = camera_ray(&c->s.camera, x, y);
		clr = vec_scal(ray_color(&r, &c->s, 0), 255);
		vec_print(&clr);
		return (0);
	}
	else
		return (0);
	window_draw(c);
	return (0);
}
