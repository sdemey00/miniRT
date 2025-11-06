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

t_bool	scene_init(t_scene *s, const char *fpath)
{
	s->ambiant.set = 0;
	s->camera.set = 0;
	s->lights_len = 0;
	s->objs_len = 0;
	if (!parse_file(fpath, s))
		return (0);
	s->camera.ratio = (float)WIDTH / (float)HEIGHT;
	s->camera.flen = tan(s->camera.fov * FT_PI / 180 / 2);
	if (VERBOSE)
		scene_print(s);
	return (1);
}
