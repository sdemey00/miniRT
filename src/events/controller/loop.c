/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:42:34 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/21 15:40:33 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controller.h"

t_bool	handle_cooldown(void)
{
	static t_ssuint		cooldown;

	cooldown++;
	if (cooldown == 10)
	{
		cooldown = 0;
		return (1);
	}
	return (0);
}

static t_bool	controller_overall(struct s_ctx *c, const struct js_event *e)
{
	float	zoom;

	if (e->type == ET_BUTTON && e->value == PRESS && e->number == ENT1_START)
		return (window_close(c));
	else if (e->type == ET_BUTTON && e->value == PRESS && e->number == ENT1_OPT)
		return (full_render(c, 0));
	else if (e->type == ET_AXIS && (e->number == ENT2_TRIG_L || \
		e->number == ENT2_TRIG_R))
	{
		zoom = (e->value + INT16_MAX) / (2.0 * INT16_MAX);
		if (e->number == ENT2_TRIG_L)
			c->s.camera.flen = tan(((c->s.camera.fov - (zoom * \
				c->s.camera.fov))) * FT_PI / 180 / 2);
		else if (e->number == ENT2_TRIG_R)
			c->s.camera.flen = tan((c->s.camera.fov + (zoom * \
				(180 - c->s.camera.fov))) * FT_PI / 180 / 2);
		return (1);
	}
	return (0);
}

int	controller_loop(struct s_ctx *c)
{
	struct js_event	e;
	t_bool			refresh;

	if (c->input == KBM)
		return (0);
	refresh = 0;
	while (read(c->w.fd_controller, &e, sizeof(e)) > 0)
	{
		if (e.type == ET_BUTTON && e.value == PRESS && e.number == ENT1_WEST)
			return (c->input = KBM);
		if (controller_overall(c, &e))
			refresh = handle_cooldown();
		else if (c->s.controlled)
			refresh = controller_object(c, &e);
		else
			refresh = controller_camera(c, &e);
		if (refresh)
		{
			window_draw(c);
			return (0);
		}
	}
	return (1);
}
