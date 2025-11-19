/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_change.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:37:17 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/14 17:37:00 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	obj_resize(t_obj *o, const int key)
{
	if (key == 't')
		o->radius += 0.1;
	else if (key == 'g' && o->radius > 0.2)
		o->radius -= 0.1;
	else if (key == 'y')
		o->height += 0.5;
	else if (key == 'h' && o->height > 1)
		o->height -= 0.5;
}

static void	obj_translate(t_obj *o, t_camera *c, const int key)
{
	if (key == 'w')
		vec_isum(&o->pos, vec_scal(c->dir, 0.5));
	else if (key == 's')
		vec_isub(&o->pos, vec_scal(c->dir, 0.5));
	else if (key == 'd')
		vec_isum(&o->pos, vec_scal(c->right, 0.5));
	else if (key == 'a')
		vec_isub(&o->pos, vec_scal(c->right, 0.5));
	else if (key == ' ')
		vec_isum(&o->pos, vec_scal((t_vec){0, 1, 0}, 0.25));
	else if (key == 'c')
		vec_isub(&o->pos, vec_scal((t_vec){0, 1, 0}, 0.25));
}

static void	obj_rotate(t_obj *o, const int key)
{
	const float	angle = FT_PI / 16;

	if (key == 'i')
		vec_irotx(&o->dir, angle);
	else if (key == 'k')
		vec_irotx(&o->dir, -angle);
	else if (key == 'l')
		vec_iroty(&o->dir, angle);
	else if (key == 'j')
		vec_iroty(&o->dir, -angle);
	else if (key == 'u')
		vec_irotz(&o->dir, angle);
	else if (key == 'o')
		vec_irotz(&o->dir, -angle);
}

static inline void	obj_set_render(t_obj *o, const int key)
{
	bitmap_switch(&o->effects, (key - '0') - 1);
}

void	obj_change(t_obj *o, struct s_ctx *c, const int key)
{
	if (ft_strchr("wasdc ", key) >= 0)
		obj_translate(o, &c->s.camera, key);
	else if (ft_strchr("ijkluo", key) >= 0)
		obj_rotate(o, key);
	else if (ft_strchr("tgyh", key) >= 0)
		obj_resize(o, key);
	else if (ft_strchr("12345678", key) >= 0)
		obj_set_render(o, key);
	if (VERBOSE)
		objs_print(o, 1);
}
