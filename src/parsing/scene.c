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

t_bool	scene_add_obj(t_scene *s, t_obj *obj, void *mlx)
{
	if (s->objs_len == MAX_OBJS)
	{
		if (obj->texture.loaded)
			mlx_destroy_image(mlx, obj->texture.img);
		if (obj->bump.texture.loaded)
			mlx_destroy_image(mlx, obj->bump.texture.img);
		return (print_error("Too much objects declarations\n"), 0);
	}
	s->objs[s->objs_len++] = *obj;
	return (1);
}

void	scene_take_control(t_scene *s, const int x, const int y)
{
	t_ray	r;

	r = camera_ray(&s->camera, x, y);
	s->controlled = get_closest_hit(&r, s).obj;
}

inline void	scene_change(t_scene *s, const int key)
{
	bitmap_switch(&s->effects, (key - '0') - 1);
}

static t_bool	create_file(int *fd)
{
	char	*filename;

	ft_printf("Name of exported file : ");
	filename = ft_gnl(0);
	if (!filename)
		return (!ft_dprintf(2, "Read stdin failed\n"));
	filename[ft_strlen(filename) - 1] = 0;
	if (!filepath_has_rt(filename))
		return (ft_free((void **)&filename, 0));
	*fd = open(filename, O_CREAT | O_EXCL | O_WRONLY, 0600);
	if (*fd < 0)
	{
		ft_dprintf(2, "Unable to open : %s\n", filename);
		free(filename);
		return (0);
	}
	free(filename);
	return (1);
}

void	scene_export(t_scene *s)
{
	int		fd;

	if (!create_file(&fd))
		return ;
	export_background(fd, &s->bg);
	export_ambiant(fd, &s->ambiant);
	export_camera(fd, &s->camera);
	export_lights(fd, s->lights, s->lights_len);
	export_objects(fd, s->objs, s->objs_len);
	close(fd);
	ft_printf("Scene exported !\n");
}
