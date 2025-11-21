/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:01:57 by sdemey            #+#    #+#             */
/*   Updated: 2025/11/21 12:32:32 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	parttracing(t_window *w, t_scene *s, const t_uint x, const t_uint y)
{
	const t_uint	offset = ceil(s->blur / 2.0);
	const t_ridx	ranges[2] = {WIDTH / 20, HEIGHT / 20};
	t_ridx			i[2];
	t_color			c;
	t_ray			r;

	i[1] = -ranges[1];
	while (i[1] < HEIGHT && i[1] <= ranges[1])
	{
		i[0] = -ranges[0];
		while (i[0] < WIDTH && i[0] <= ranges[0])
		{
			if (!((i[0] % s->blur) - offset == 0 && (i[1] % s->blur) - \
				offset == 0))
			{
				r = camera_ray(&s->camera, x + i[0], y + i[1]);
				c = vec_scal(ray_color(&r, s, 0), 255);
				mlx_pixel_put(w->mlx, w->win, x + i[0], y + i[1], \
					color_int(&c));
			}
			i[0]++;
		}
		i[1]++;
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
