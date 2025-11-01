/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:31:38 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/01 18:29:30 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	raytracing(t_window *w, t_scene *s)
{
	t_idx	x;
	t_idx	y;
	t_color	start = (t_color){0, 255, 0};
	const t_color	step_x = vec_rscal(vec_sub((t_color){255, 0, 0}, start), WIDTH);
	const t_color	step_y = vec_rscal(vec_sub((t_color){0, 0, 255}, start), HEIGHT);
	
	(void)s;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			window_draw_pixel(w, x, y, color_int(&start));
			vec_isum((t_vec *)&start, step_x);
			x++;
		}
		vec_isum((t_vec *)&start, step_y);
		y++;
	}
}
