/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 12:37:08 by sdemey            #+#    #+#             */
/*   Updated: 2025/11/17 14:41:11 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	normalize_lights(t_scene *s)
{
	t_idx	i;

	i = 0;
	while (i < s->lights_len)
	{
		s->lights[i].norm = vec_rscal(s->lights[i].color, 255.0);
		i++;
	}
}

void	obj_init(t_obj *o)
{
	o->dir = (t_vec){0, 1, 0};
	o->shininess = DFLT_BRIGHT;
	o->reflexion = DFLT_REFLECT;
	o->effects = 0b11101111;
	o->texture.loaded = 0;
	o->bump.texture.loaded = 0;
	o->bump.e_type = NO_BUMP;
}

t_bool	scene_init(t_scene *s, const char *fpath, void *mlx)
{
	s->ambiant.set = 0;
	s->camera.set = 0;
	s->lights_len = 0;
	s->objs_len = 0;
	s->controlled = 0;
	s->reticle = 0;
	s->blur = 30;
	s->bg = (t_color){0, 0, 0};
	s->bg_set = 0;
	s->effects = 0b11111111;
	if (!parse_file(fpath, s, mlx))
		return (0);
	s->camera.ratio = (float)WIDTH / (float)HEIGHT;
	s->camera.flen = tan(s->camera.fov * FT_PI / 180 / 2);
	s->ambiant.light_norm = vec_rscal(s->ambiant.color, 255.0);
	normalize_lights(s);
	if (VERBOSE)
		scene_print(s);
	return (1);
}
