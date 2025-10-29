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

#include <stdio.h>

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

int	main(void)
{
	t_ectx	ctx;

	if (!gctx_init(&ctx.g))
		exit(1);
	mlx_hook(ctx.g.win, WIN_CLOSE, 0, ectx_close, &ctx);
	mlx_key_hook(ctx.g.win, event_handler, &ctx);
	mlx_loop(ctx.g.mlx);
}
