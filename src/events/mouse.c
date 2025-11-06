#include "minirt.h"

/*
mlx_mouse_get_pos(c.w.mlx, c.w.win, &x, &y);
mlx_mouse_hide(c.w.mlx, c.w.win);
mlx_mouse_move(c.w.mlx, c.w.win, x, y);
*/

/* Hooks mouse clicking events */
int	mouse_handler(int key, int x, int y, struct s_ctx *c)
{
	(void)c;
	if (VERBOSE)
		ft_printf("mouse pressed : %d %d %d\n", key, x, y);
	return (0);
}