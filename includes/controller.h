/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 00:05:42 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/19 00:15:59 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLLER_H
# define CONTROLLER_H

# include "minirt.h"

// Event type
# define RT_ET_BUTTON	1
# define RT_ET_AXIS		2
# define RT_ET_INIT		129
# define RT_ET_CALIBR	130

// Event value
# define RT_EV_RELEASE	0
# define RT_EV_PRESS	1

// Event number when type == 1 (BUTTON)
# define RT_EN_SOUTH	0
# define RT_EN_EAST		1
# define RT_EN_NORTH	2
# define RT_EN_WEST		3
# define RT_EN_L_BACK	4
# define RT_EN_R_BACK	5
# define RT_EN_L_TRIG	6
# define RT_EN_R_TRIG	7
# define RT_EN_OPT		8
# define RT_EN_START	9
# define RT_EN_HOME		10
# define RT_EN_L_JS		11
# define RT_EN_R_JS		12

// Event number when type == 2 (AXIS)
# define JS_L_X			0
# define JS_L_Y			1
# define TRIG_L			2
# define JS_R_X			3
# define JS_R_Y			4
# define TRIG_R			5
# define DPAD_X			6
# define DPAD_Y			7

# define INT16_MAX		32767

// events/controller/loop.c
int		controller_loop(struct s_ctx *c);

#endif // CONTROLLER_H