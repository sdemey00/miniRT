/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 08:50:17 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/04 14:21:51 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	key_handler(int key, struct s_ctx *c)
{
	if (VERBOSE)
		ft_printf("key pressed : %d\n", key);
	if (key == K_ESC)
		window_close((void *)&c->w);
	if (ft_strchr("qweasduiojkl", key) >= 0)
		return (camera_change(&c->s.camera, key));
	return (0);
}

static int	event_handler(int key, void *ctx)
{
	struct s_ctx	*c;

	c = (struct s_ctx *)ctx;
	if (key_handler(key, ctx))
	{
		if (VERBOSE)
			camera_print(c->s.camera);
		window_draw(&c->w, &c->s);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	struct s_ctx	c;

	if (argc != 2)
	{
		print_error("Usage: ./miniRT <scene.rt>\n");
		return (0);
	}
	scene_init(&c.s);
	if (!parse_file(argv[1], &c.s))
		return (-1);
	if (VERBOSE)
		scene_print(&c.s);
	if (!window_init(&c.w))
		return (1);
	window_draw(&c.w, &c.s);
	mlx_hook(c.w.win, WIN_CLOSE, 0, window_close, &c);
	mlx_key_hook(c.w.win, event_handler, &c);
	mlx_loop(c.w.mlx);
	return (0);
}
