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

static void	normalize_lights(t_scene *s)
{
	t_idx	i;

	i = 0;
	while (i < s->lights_len)
	{
		s->lights[i].light_norm = vec_rscal(s->lights[i].color, 255.0);
		i++;
	}
}

t_bool	scene_init(t_scene *s, const char *fpath)
{
	s->ambiant.set = 0;
	s->camera.set = 0;
	s->lights_len = 0;
	s->objs_len = 0;
	s->controlled = 0;
	s->blur = 20;
	if (!parse_file(fpath, s))
		return (0);
	s->camera.ratio = (float)WIDTH / (float)HEIGHT;
	s->camera.flen = tan(s->camera.fov * FT_PI / 180 / 2);
	s->ambiant.light_norm = vec_rscal(s->ambiant.color, 255.0);
	normalize_lights(s);
	if (VERBOSE)
		scene_print(s);
	return (1);
}

void	scene_take_control(t_scene *s, const int x, const int y)
{
	t_ray	r;
	float	t;

	t = INFINITY;
	r = camera_ray(&s->camera, x, y);
	s->controlled = get_closest_hit(&r, &t, s);
}
