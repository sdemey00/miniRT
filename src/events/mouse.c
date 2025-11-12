/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:01:57 by sdemey            #+#    #+#             */
/*   Updated: 2025/11/12 13:07:18 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	mouse_press(int key, int x, int y, struct s_ctx *c)
{
	if (VERBOSE)
		ft_printf("Mouse pressed with key %d at %d %d\n", key, x, y);
	if (key == 1)
		scene_take_control(&c->s, x, y);
	else if (key == 3)
		c->s.controlled = 0;
	return (0);
}
