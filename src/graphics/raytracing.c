/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:02:07 by mmichele          #+#    #+#             */
/*   Updated: 2026/04/16 18:29:40 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	full_render(struct s_ctx *c, const t_idx i)
{
	const t_bool		temp_reticle = c->s.reticle;
	double				start_time;
	static void* (*const rasterizer[3])(void*) = \
		{raster_evenly, raster_grid, raster_linear};
	pthread_t			threads[RENDER_THREADS];
	t_thread_ctx		thread_ctxs[RENDER_THREADS];
	pthread_mutex_t		mutex = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;

	if (c->state == RENDERED)
		return (0);
	c->state = RENDERING;
	c->s.reticle = 0;
	ft_printf("Render");
	start_time = time_now();
	for (unsigned int j = 0; j < RENDER_THREADS; j++)
	{
		thread_ctxs[j].w = &c->w;
		thread_ctxs[j].s = c->s;
		thread_ctxs[j].id = j;
		thread_ctxs[j].mtx = &mutex;
		pthread_create(&threads[j], 0, rasterizer[i], &thread_ctxs[j]);
	}
	for (unsigned int j = 0; j < RENDER_THREADS; j++)
	{
		pthread_join(threads[j], 0);
	}
	ft_printf("ed in %.3fs\n", (time_now() - start_time) / 1000);
	c->s.reticle = temp_reticle;
	c->state = RENDERED;
	return (0);
}
