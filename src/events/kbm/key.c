/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:01:45 by sdemey            #+#    #+#             */
/*   Updated: 2025/11/20 11:19:44 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	change_blur(struct s_ctx *c, const int key)
{
	if (key == K_DOWN && c->s.blur > 5)
		c->s.blur--;
	else if (key == K_UP && c->s.blur < 50)
		c->s.blur++;
}

static t_bool	key_release2(const int key, struct s_ctx *c)
{
	if (!c->s.controlled && ('1' <= key && key <= '8'))
		scene_change(&c->s, key);
	else if (key == 'e')
		scene_export(&c->s);
	else if (key == 'x')
		c->s.reticle = !c->s.reticle;
	else
		return (0);
	return (1);
}

int	key_release(int key, struct s_ctx *c)
{
	if (VERBOSE)
		ft_printf("key released : %d\n", key);
	if (key == K_ESC)
		window_close(&c->w);
	if (key == 'z')
		c->input = CONTROLLER;
	else if (c->state == RENDERING)
		return (1);
	else if (key == 'p')
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
	else if (!key_release2(key, c))
		return (1);
	window_draw(c);
	return (0);
}
