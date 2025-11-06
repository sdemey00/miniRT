#include "minirt.h"

int	key_handler(int key, struct s_ctx *c)
{
	if (VERBOSE)
		ft_printf("key pressed : %d\n", key);
	if (key == K_ESC)
		window_close(&c->w);
	else if (ft_strchr("swad cuiojkl", key) >= 0)
	{
		camera_change(&c->s.camera, key);
		c->t = time_now();
		window_draw(&c->w, &c->s, blurtracing);
	}
	return (0);
}