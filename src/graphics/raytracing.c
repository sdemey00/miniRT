/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:02:07 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/21 17:14:29 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	full_render(struct s_ctx *c, const t_idx i)
{
	const t_bool		temp_reticle = c->s.reticle;
	double				start_time;
	static void (*const	rasterizer[3])(t_window *, t_scene *) = \
		{raster_evenly, raster_grid, raster_linear};

	if (c->state == RENDERED)
		return (0);
	c->state = RENDERING;
	c->s.reticle = 0;
	ft_printf("Render");
	start_time = time_now();
	rasterizer[i](&c->w, &c->s);
	ft_printf("ed in %.3fs\n", (time_now() - start_time) / 1000);
	c->s.reticle = temp_reticle;
	c->state = RENDERED;
	return (0);
}
