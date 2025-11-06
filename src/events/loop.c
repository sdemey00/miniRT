#include "minirt.h"

int	loop_handler(struct s_ctx *c)
{
	if (time_now() - c->t >= 2)
	{
		window_draw(&c->w, &c->s, raytracing);
		c->t = 0;
	}
	return (0);
}