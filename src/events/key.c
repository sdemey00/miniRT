/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:01:45 by sdemey            #+#    #+#             */
/*   Updated: 2025/11/12 15:27:28 by mmichele         ###   ########.fr       */
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
		full_render(c);
	else if (!c->s.controlled && ft_strchr("wasdc ijkl-=", key) >= 0)
		camera_change(c, key);
	else if (key == K_UP || key == K_DOWN)
	{
		if (key == K_DOWN && c->s.blur > 10)
			c->s.blur--;
		else if (key == K_UP && c->s.blur < 50)
			c->s.blur++;
		window_draw(&c->w, &c->s);
	}
	else if (c->s.controlled && key == 'e')
		c->s.controlled = 0;
	else if (!c->s.controlled && key == 'e')
		scene_take_control(&c->s, WIDTH / 2.0, HEIGHT / 2.0);
	else if (c->s.controlled && ft_strchr("wasdc ijkluotgyh", key) >= 0)
		obj_change(c->s.controlled, c, key);
	return (0);
}
