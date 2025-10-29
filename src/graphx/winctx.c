/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winctx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:06:09 by mmichele          #+#    #+#             */
/*   Updated: 2025/10/29 12:49:15 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	gctx_init(t_gctx *g)
{
	g->mlx = mlx_init();
	if (!g->mlx)
		return (0);
	g->win = mlx_new_window(g->mlx, WIDTH, HEIGHT, "miniRT");
	if (!g->win)
		return (ft_free(g->mlx, 0));
	return (1);
}

t_bool	gctx_free(t_gctx *g)
{
	if (g->mlx && g->win)
	{
		mlx_destroy_window(g->mlx, g->win);
		g->win = 0;
	}
	if (g->mlx)
	{
		mlx_destroy_display(g->mlx);
		free(g->mlx);
		g->mlx = 0;
	}
	return (0);
}

int	ectx_close(void *ectx)
{
	t_ectx	*e;

	e = (t_ectx *)ectx;
	gctx_free(&e->g);
	exit(0);
}
