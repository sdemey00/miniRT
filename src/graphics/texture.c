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

// typedef struct s_tex
// {
// 	void	*img;
// 	char	*addr;
// 	int		w;
// 	int		h;
// 	int		bpp;
// 	int		size_line;
// 	int		endian;
//     char    *path;
// 	t_bool	loaded;
// }	t_tex;
//
// void	load_texture(t_tex *tex, void *mlx, char *path)
// {
// 	tex->img = mlx_xpm_file_to_image(mlx, path, &tex->w, &tex->h);
// 	if (!tex->img)
// 	{
// 		tex->loaded = 0;
// 		return ;
// 	}
// 	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp,
// 			&tex->size_line, &tex->endian);
// 	tex->loaded = 1;
// }
//
// static int	get_tex_pixel(t_tex *tex, int x, int y)
// {
// 	char	*px;
//
// 	px = tex->addr + (y * tex->size_line)
// 		+ (x * (tex->bpp / 8));
// 	return (*(int *)px);
// }
//
// t_color	texture_color(t_tex *tex, t_hit *hitten)
// {
// 	int		x;
// 	int		y;
// 	int		rgb;
//
// 	hitten->u = fmodf(hitten->u, 1.0);
// 	hitten->v = fmodf(hitten->v, 1.0);
// 	if (hitten->u < 0)
// 		hitten->u += 1.0;
// 	if (hitten->v < 0)
// 		hitten->v += 1.0;
//
// 	x = (int)(hitten->u * tex->w);
// 	y = (int)(hitten->v * tex->h);
//
// 	if (x >= tex->w)
// 		x = tex->w - 1;
// 	if (y >= tex->h)
// 		y = tex->h - 1;
//
// 	rgb = get_tex_pixel(tex, x, y);
// 	return ((t_color){
// 		(rgb >> 16) & 255,
// 		(rgb >> 8) & 255,
// 		rgb & 255});
// }
