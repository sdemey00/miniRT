/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:27:47 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/20 11:46:46 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controller.h"

static t_bool	handle_buttons(struct s_ctx *c, const struct js_event *e)
{
	if (e->value == PRESS && e->number == ENT1_R_BACK)
		c->s.controlled = 0;
	else if (e->value == PRESS && e->number == ENT1_SOUTH)
		vec_isum(&c->s.controlled->pos, vec_scal((t_vec){0, 1, 0}, 0.25));
	else
		return (0);
	return (1);
}

static t_bool	handle_left_js(struct s_ctx *c, const struct js_event *e)
{
	short int	coords[2];
	t_vec		a;

	coords[e->number] = e->value;
	a = (t_vec){coords[0] / (float)INT16_MAX, coords[1] / (float)INT16_MAX, 0};
	vec_isum(&c->s.controlled->pos, vec_scal(c->s.camera.dir, -a.y / 10));
	vec_isum(&c->s.controlled->pos, vec_scal(c->s.camera.right, a.x / 10));
	return (handle_cooldown());
}

static t_bool	handle_right_js(struct s_ctx *c, const struct js_event *e)
{
	short int	coords[2];
	t_vec		a;

	coords[e->number - ENT2_JS_R_X] = e->value;
	a = (t_vec){coords[0] / (float)INT16_MAX, coords[1] / (float)INT16_MAX, 0};
	c->s.camera.dir = vec_rot(&c->s.camera.dir, &c->s.camera.right, \
		(FT_PI / 256) * a.y);
	vec_iroty(&c->s.camera.dir, (FT_PI / 256) * a.x);
	return (handle_cooldown());
}

static t_bool	handle_dpad(struct s_ctx *c, const struct js_event *e)
{
	if (e->number == ENT2_DPAD_Y && e->value == INT16_MAX)
		vec_isum(&c->s.controlled->pos, vec_scal((t_vec){0, -1, 0}, 0.25));
	else if (e->number == ENT2_DPAD_X && e->value == -INT16_MAX && \
		c->s.blur > 5)
		c->s.blur--;
	else if (e->number == ENT2_DPAD_X && e->value == INT16_MAX && \
		c->s.blur < 50)
		c->s.blur++;
	else
		return (0);
	return (1);
}

t_bool	controller_object(struct s_ctx *c, const struct js_event *e)
{
	if (e->type == ET_BUTTON)
		return (handle_buttons(c, e));
	else if (e->type == ET_AXIS && (e->number == ENT2_JS_L_X || \
		e->number == ENT2_JS_L_Y))
		return (handle_left_js(c, e));
	else if (e->type == ET_AXIS && (e->number == ENT2_JS_R_X || \
		e->number == ENT2_JS_R_Y))
		return (handle_right_js(c, e));
	else if (e->type == ET_AXIS && (e->number == ENT2_DPAD_X || \
		e->number == ENT2_DPAD_Y))
		return (handle_dpad(c, e));
	return (0);
}
