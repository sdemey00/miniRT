/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 00:05:42 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/19 17:27:42 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLLER_H
# define CONTROLLER_H

# include "minirt.h"
# include <linux/joystick.h>

// Event type
# define ET_BUTTON	1
# define ET_AXIS	2
# define ET_INIT	129
# define ET_CALIBR	130

// Event value
# define RELEASE	0
# define PRESS		1

// Event number when type == 1 (BUTTON)
# define ENT1_SOUTH		0
# define ENT1_EAST		1
# define ENT1_NORTH		2
# define ENT1_WEST		3
# define ENT1_L_BACK	4
# define ENT1_R_BACK	5
# define ENT1_L_TRIG	6
# define ENT1_R_TRIG	7
# define ENT1_OPT		8
# define ENT1_START		9
# define ENT1_HOME		10
# define ENT1_L_JS		11
# define ENT1_R_JS		12

// Event number when type == 2 (AXIS)
# define ENT2_JS_L_X	0
# define ENT2_JS_L_Y	1
# define ENT2_TRIG_L	2
# define ENT2_JS_R_X	3
# define ENT2_JS_R_Y	4
# define ENT2_TRIG_R	5
# define ENT2_DPAD_X	6
# define ENT2_DPAD_Y	7

# define INT16_MAX		32767

// events/controller/loop.c
t_bool	handle_cooldown(void);
int		controller_loop(struct s_ctx *c);

// events/controller/camera.c
t_bool	controller_camera(struct s_ctx *c, const struct js_event *e);

// events/controller/object.c
t_bool	controller_object(struct s_ctx *c, const struct js_event *e);

#endif // CONTROLLER_H