/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:01:45 by sdemey            #+#    #+#             */
/*   Updated: 2025/11/14 17:04:21 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	change_blur(struct s_ctx *c, const int key)
{
	if (key == K_DOWN && c->s.blur > 10)
		c->s.blur--;
	else if (key == K_UP && c->s.blur < 50)
		c->s.blur++;
}

int	key_release(int key, struct s_ctx *c)
{
	if (VERBOSE)
		ft_printf("key released : %d\n", key);
	if (key == K_ESC)
		window_close(&c->w);
	else if (key == 'p' && !c->rendering)
		return (full_render(c));
	else if (!c->s.controlled && ft_strchr("wasdc ijkl-=", key) >= 0)
		camera_change(c, key);
	else if (key == K_UP || key == K_DOWN)
		change_blur(c, key);
	else if (c->s.controlled && key == 'f')
		c->s.controlled = 0;
	else if (!c->s.controlled && key == 'f')
		scene_take_control(&c->s, WIDTH / 2.0, HEIGHT / 2.0);
	else if (c->s.controlled && ft_strchr("wasdc ijkluotgyh12345678", key) >= 0)
		obj_change(c->s.controlled, c, key);
	else if (!c->s.controlled && ft_strchr("12345678", key) >= 0)
		scene_change(&c->s, key);
	else if (key == 'x')
		c->s.reticle = !c->s.reticle;
	window_draw(&c->w, &c->s);
	c->rendering = 0;
	return (0);
}
