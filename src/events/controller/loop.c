/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:42:34 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/19 01:19:44 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controller.h"
#include <linux/joystick.h>

/*
make a function that returns 1 if needs to window draw and break
0 otherwise
*/

/*
Need to set the correct moving directions based on camera direction,
not space coordinates
*/
int	controller_loop(struct s_ctx *c)
{
	struct js_event	e;
	short int		coords[2] = {0, 0};
	t_vec			a;
	t_ssuint		cooldown;

	cooldown = 0;
	while (read(c->w.fd_controller, &e, sizeof(e)) > 0)
	{
		if (e.type == RT_ET_BUTTON && e.value == RT_EV_PRESS && e.number == RT_EN_START)
			return (window_close(&c->w));
		else if (e.type == RT_ET_BUTTON && e.value == RT_EV_PRESS && e.number == RT_EN_OPT)
			return (full_render(c));
		else if (e.type == RT_ET_BUTTON && e.value == RT_EV_PRESS && e.number == RT_EN_NORTH)
		{
			c->s.reticle = !c->s.reticle;
			window_draw(&c->w, &c->s);
			break ;
		}
		else if (e.type == RT_ET_AXIS)
		{
			if (e.number == 0 || e.number == 1)
			{
				coords[e.number] = e.value;
				a = (t_vec){coords[0] / (float)INT16_MAX, coords[1] / (float)INT16_MAX, 0};
				if (cooldown == 1)
				{
					//vec_isum(&c->s.camera.pos, vec_scal(c->dir, 0.5));
					vec_isum(&c->s.camera.pos, vec_scal((t_vec){-a.x, 0, a.y}, 0.1));
					window_draw(&c->w, &c->s);
					cooldown = 0;
					return (0);
				}
				cooldown++;
			}
			else if (e.number == 2)
			{
				//ft_printf("left trigger\n");
			}
			else if (e.number == 3 || e.number == 4)
			{
				//ft_printf("right js\n");
			}
			else if (e.number == 5)
			{
				//ft_printf("right trigger\n");
			}
			else if (e.number == 6 || e.number == 7)
			{
				coords[e.number - 6] = e.value;
				if (coords[1] == -INT16_MAX)
					vec_isum(&c->s.camera.pos, vec_scal((t_vec){0, 1, 0}, 0.25));
				else if (coords[1] == INT16_MAX)
					vec_isum(&c->s.camera.pos, vec_scal((t_vec){0, -1, 0}, 0.25));
				else if (coords[0] == -INT16_MAX)
					ft_printf("LEFT");
				else if (coords[0] == INT16_MAX)
					ft_printf("RIGHT");
				window_draw(&c->w, &c->s);
				return (0);
			}
			else
				ft_printf("%d\n", e.number);
		}
		else if (e.type == RT_ET_AXIS || e.type == RT_ET_BUTTON)
			ft_printf("%d %d %d\n", e.value, e.type, e.number);
	}
	return (0);
}
