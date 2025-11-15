/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:56:14 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/06 18:46:41 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_bool	scene_add_obj(t_scene *s, t_obj *obj)
{
	if (s->objs_len == MAX_OBJS)
		return (print_error("Too much objects declarations\n"), 0);
	s->objs[s->objs_len++] = *obj;
	return (1);
}

void	scene_take_control(t_scene *s, const int x, const int y)
{
	t_ray	r;

	r = camera_ray(&s->camera, x, y);
	s->controlled = get_closest_hit(&r, s).obj;
}

void	scene_change(t_scene *s, const int key)
{
	bitmap_switch(&s->effects, (key - '0') - 1);
}
