#include "minirt.h"

int	window_close(t_window *w)
{
	window_free(w);
	exit(0);
}