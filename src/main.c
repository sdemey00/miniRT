/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 08:50:17 by mmichele          #+#    #+#             */
/*   Updated: 2025/10/29 15:12:48 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	key_handler(int key, void *ctx)
{
	t_ectx	*c;

	c = (t_ectx *)ctx;
	if (key == KEY_ESC)
		ectx_close(c);
	if (key == 'w' || key == 'a' || key == 's' || key == 'd')
	{
		//camera_move();
		return (1);
	}
	return (0);
}

static int	event_handler(int key, void *ctx)
{
	if (key_handler(key, ctx))
	{
		//redraw image after valid key move
		printf("Hello\n;");
	}
	return (0);
}

static void	scene_init(t_scene *scene)
{
	scene->planes_idx = 0;
	scene->spheres_idx = 0;
	scene->cylinders_idx = 0;
	scene->lights_idx = 0;
	scene->camera.set = 0;
	scene->ambiant.set = 0;
}

int	main(int argc, char **argv)
{
	t_ectx	ctx;
	t_scene	scene;

	if (argc != 2)
	{
		ft_dprintf(2, "Usage: ./miniRT <scene.rt>");
		return (0);
	}
	scene_init(&scene);
	if (!parse_file(argv[1], &scene))
		return (ft_dprintf(2, "Error occured during parsing\n"), -1);
	printf("Scene parsed\n");
	print_scene_infos(&scene);
	return (0);
	if (!gctx_init(&ctx.g))
		exit(1);
	mlx_hook(ctx.g.win, WIN_CLOSE, 0, ectx_close, &ctx);
	mlx_key_hook(ctx.g.win, event_handler, &ctx);
	mlx_loop(ctx.g.mlx);
}
