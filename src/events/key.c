/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemey <sdemey@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:01:45 by sdemey            #+#    #+#             */
/*   Updated: 2025/11/07 13:01:46 by sdemey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	key_handler(int key, struct s_ctx *c)
{
	if (VERBOSE)
		ft_printf("key pressed : %d\n", key);
	if (key == K_ESC)
		window_close(&c->w);
	else if (ft_strchr("swad cuiojkl", key) >= 0)
	{
		camera_change(&c->s.camera, key);
		c->t = time_now();
		window_draw(&c->w, &c->s, blurtracing);
	}
	return (0);
}
