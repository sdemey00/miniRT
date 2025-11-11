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

int	main(int argc, char **argv)
{
	struct s_ctx	c;

	if (argc != 2)
		return (!!dprintf(2, "Usage: %s <scene.rt>\n", argv[0]));
	if (!scene_init(&c.s, argv[1]) || !window_init(&c.w))
		return (1);
	window_draw(&c.w, &c.s, blurtracing);
	mlx_hook(c.w.win, WIN_CLOSE, 0, window_close, &c.w);
	mlx_hook(c.w.win, 3, 2, key_release, &c);
	mlx_hook(c.w.win, 4, 1L << 2, mouse_press, &c);
	mlx_loop(c.w.mlx);
	return (0);
}
