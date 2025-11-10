/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 08:50:17 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/06 18:42:36 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	key_press(struct s_ctx *c)
{
	(void)c;
	ft_printf("key_pressed\n");
	return (0);
}

int	main(int argc, char **argv)
{
	struct s_ctx	c;

	c.t = 0;
	c.rendered = 0;
	if (argc != 2)
		return (!!dprintf(2, "Usage: %s <scene.rt>\n", argv[0]));
	if (!scene_init(&c.s, argv[1]) || !window_init(&c.w))
		return (1);
	mlx_hook(c.w.win, WIN_CLOSE, 0, window_close, &c.w);
	//mlx_hook(c.w.win, 2, 1L << 0, key_press, &c);		// KeyPress
	mlx_key_hook(c.w.win, key_handler, &c);				// KeyRelease
	//mlx_mouse_hook(c.w.win, mouse_handler, &c);			
	mlx_loop_hook(c.w.mlx, loop_handler, &c);
	mlx_loop(c.w.mlx);
	return (0);
}
