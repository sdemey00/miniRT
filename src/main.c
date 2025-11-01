/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 08:50:17 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/01 14:25:03 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	key_handler(int key, void *window)
{
	t_window	*w;

	w = (t_window *)window;
	if (key == KEY_ESC)
		window_close(window);
	if (key == 'w' || key == 'a' || key == 's' || key == 'd')
	{
		if (VERBOSE)
			ft_printf("key pressed : %c\n", key);
		//camera_move();
		return (1);
	}
	return (0);
}

static int	event_handler(int key, void *window)
{
	if (key_handler(key, window))
	{
		//redraw image after valid key move
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_scene		s;
	t_window	w;

	if (argc != 2)
	{
		ft_dprintf(2, "Usage: ./miniRT <scene.rt>\n");
		return (0);
	}
	scene_init(&s);
	if (!parse_file(argv[1], &s))
		return (ft_dprintf(2, "Error occured during parsing\n"), -1);
	printf("Scene parsed\n");
	print_scene_infos(&s);
	if (!window_init(&w))
		return (1);
	window_draw(&w);
	mlx_hook(w.win, WIN_CLOSE, 0, window_close, &w);
	mlx_key_hook(w.win, event_handler, &w);
	mlx_loop(w.mlx);
	return (0);
}
