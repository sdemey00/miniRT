/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:56:58 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/05 13:57:00 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

# define MOVE 2

static void	camera_translate(t_camera *c, unsigned int key)
{
	if (key == 'w')
		c->pos.x += MOVE;
	else if (key == 'a')
		c->pos.y -= MOVE;
	else if (key == 's')
		c->pos.x -= MOVE;
	else if (key == 'd')
		c->pos.y += MOVE;
	else if (key == 'q')
		c->pos.z += MOVE;
	else if (key == 'e')
		c->pos.z -= MOVE;
}

static void	camera_rotate(t_camera *c, unsigned int key)
{
	if (key == K_UP)
		c->dir.x += MOVE;
	else if (key == K_LEFT)
		c->dir.y -= MOVE;
	else if (key == K_DOWN)
		c->dir.x -= MOVE;
	else if (key == K_RIGHT)
		c->dir.y -= MOVE;
}

t_bool	camera_change(t_camera *c, short unsigned int key)
{
	if (key == 'w' || key == 'a' || key == 's' || key == 'd' || \
		key == 'q' || key == 'e')
		camera_translate(c, key);
	else if (key == K_UP || key == K_DOWN || key == K_RIGHT || key == K_DOWN)
		camera_rotate(c, key);
	return (1);
}
