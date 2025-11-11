/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:01:45 by sdemey            #+#    #+#             */
/*   Updated: 2025/11/11 17:46:04 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	key_release(int key, struct s_ctx *c)
{
	if (VERBOSE)
		ft_printf("key released : %d\n", key);
	if (key == K_ESC)
		window_close(&c->w);
	else if (key == 'p' && !c->rendering)
	{
		ft_printf("Rendering ...");
		c->rendering = 1;
		window_draw(&c->w, &c->s, raytracing);
		ft_printf("\n");
	}
	else if (ft_strchr("wasdc ", key) >= 0)
	{
		camera_translate(&c->s.camera, key);
		window_draw(&c->w, &c->s, blurtracing);
		c->rendering = 0;
	}
	else if (ft_strchr("ijkl", key) >= 0)
	{
		camera_rotate(&c->s.camera, key);
		window_draw(&c->w, &c->s, blurtracing);
		c->rendering = 0;
	}
	return (0);
}
