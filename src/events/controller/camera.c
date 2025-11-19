/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:28:22 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/19 17:51:21 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controller.h"

t_bool	controller_camera(struct s_ctx *c, const struct js_event *e)
{
	short int		coords[2];
	t_vec			a;

	if (e->type == ET_BUTTON)
	{
		if (e->value == PRESS && e->number == ENT1_NORTH)
			c->s.reticle = !c->s.reticle;
		else if (e->value == PRESS && e->number == ENT1_R_BACK)
			scene_take_control(&c->s, WIDTH / 2.0, HEIGHT / 2.0);
		else if (e->value == PRESS && e->number == ENT1_SOUTH)
			vec_isum(&c->s.camera.pos, vec_scal((t_vec){0, 1, 0}, 0.25));
		else
			return (0);
		return (1);
	}
	else if (e->type == ET_AXIS)
	{
		if (e->number == ENT2_JS_L_X || e->number == ENT2_JS_L_Y)
		{
			coords[e->number] = e->value;
			a = (t_vec){coords[0] / (float)INT16_MAX, coords[1] / (float)INT16_MAX, 0};
			vec_isum(&c->s.camera.pos, vec_scal(c->s.camera.dir, -a.y / 7));
			vec_isum(&c->s.camera.pos, vec_scal(c->s.camera.right, a.x / 7));
			return (handle_cooldown());
		}
		else if (e->number == ENT2_JS_R_X || e->number == ENT2_JS_R_Y)
		{
			coords[e->number - ENT2_JS_R_X] = e->value;
			a = (t_vec){coords[0] / (float)INT16_MAX, coords[1] / (float)INT16_MAX, 0};
			c->s.camera.dir = vec_rot(&c->s.camera.dir, &c->s.camera.right, (FT_PI / 256) * a.y);
			vec_iroty(&c->s.camera.dir, (FT_PI / 256) * a.x);
			return (handle_cooldown());
		}
		else if (e->number == ENT2_DPAD_X || e->number == ENT2_DPAD_Y)
		{
			coords[e->number - ENT2_DPAD_X] = e->value;
			if (coords[1] == -INT16_MAX)
				;
			else if (coords[1] == INT16_MAX)
				vec_isum(&c->s.camera.pos, vec_scal((t_vec){0, -1, 0}, 0.25));
			else if (coords[0] == -INT16_MAX)
				c->s.blur--;
			else if (coords[0] == INT16_MAX)
				c->s.blur++;
			return (1);
		}
	}
	return (0);
}
