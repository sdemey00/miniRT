/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemey <sdemey@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:04:46 by sdemey            #+#    #+#             */
/*   Updated: 2025/11/24 12:05:11 by sdemey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	textures_free(t_window *w, t_scene *s)
{
	t_idx	i;

	i = 0;
	while (i < s->objs_len)
	{
		if (s->objs[i].texture.loaded)
			mlx_destroy_image(w->mlx, s->objs[i].texture.img);
		if (s->objs[i].bump.texture.loaded)
			mlx_destroy_image(w->mlx, s->objs[i].bump.texture.img);
		i++;
	}
}
