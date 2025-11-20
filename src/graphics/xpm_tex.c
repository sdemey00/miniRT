/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemey <sdemey@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 10:32:24 by sdemey            #+#    #+#             */
/*   Updated: 2025/11/15 10:32:26 by sdemey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	checkboard_pattern(t_hit *hitten)
{
	float	scale;

	scale = 30.0;
	if (hitten->obj->e_type == PLA || hitten->obj->e_type == CIR)
		scale = 5.0;
	if (((int)floor(hitten->uv.x * scale)
			+ (int)floor(hitten->uv.y * scale)) % 2 == 0)
		return (hitten->obj->color);
	return ((t_color){255, 255, 255});
}

void	load_texture(t_tex *tex, void *mlx, char *path)
{
	(void)path;
	tex->img = mlx_xpm_file_to_image(mlx, path, &tex->w, &tex->h);
	if (!tex->img)
	{
		tex->loaded = 0;
		return ;
	}
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp,
			&tex->size_line, &tex->endian);
	tex->loaded = 1;
}

int	get_tex_pixel(t_tex *tex, int x, int y)
{
	const char	*px = tex->addr + (y * tex->size_line) + (x * (tex->bpp / 8));

	return (*(int *)px);
}

t_color	texture_color(t_tex *tex, t_hit *hitten)
{
	int		x;
	int		y;
	int		rgb;

	x = (int)(hitten->uv.x * tex->w);
	y = (int)(hitten->uv.y * tex->h);
	if (x >= tex->w)
		x = tex->w - 1;
	if (y >= tex->h)
		y = tex->h - 1;
	rgb = get_tex_pixel(tex, x, y);
	return ((t_color){(rgb >> 16) & 255, (rgb >> 8) & 255, rgb & 255});
}
