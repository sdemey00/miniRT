/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:31:38 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/04 17:59:50 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	raytracing(t_window *w, t_scene *s)
{
	t_idx	i;
	t_idx	j;
	t_color	c;
	t_ray	r;

	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			r = camera_ray(&s->camera, i, j);
			c = ray_color(&r, s);
			window_draw_pixel(w, i, j, color_int(&c));
			i += 1;
		}
		j += 1;
	}
}
