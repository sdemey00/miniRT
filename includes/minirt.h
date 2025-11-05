/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:02:14 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/04 17:48:47 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# ifndef VERBOSE
#  define VERBOSE 0
# endif

# ifdef WIDTH
#  if WIDTH < 100 || 3800 < WIDTH
#   undef WIDTH
#  endif
# endif
# ifndef WIDTH
#  define WIDTH 1600
# endif

# ifdef HEIGHT
#  if HEIGHT < 100 || 2000 < HEIGHT
#   undef HEIGHT
#  endif
# endif
# ifndef HEIGHT
#  define HEIGHT 900
# endif

# include <math.h>
# include <stdio.h>
# include <fcntl.h>

# include "libft.h"
# include "mlx.h"

# include "structs.h"
# include "parsing.h"

/* MLX controller event codes */
# define WIN_CLOSE	17
# define K_ESC		65307

# define MOVE_SPEED	2

/* MLX pixel grid manipulation */
typedef struct s_image
{
	void	*ptr;
	char	*address;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_image;

/* Graphical library contexti -> MLX */
typedef struct s_window
{
	void	*mlx;
	void	*win;
	t_image	img;
}	t_window;

struct s_ctx
{
	t_window	w;
	t_scene		s;
};

// graphics/window.c
t_bool	window_init(t_window *w);
void	window_draw(t_window *w, t_scene *s);
void	window_draw_pixel(t_window *w, t_uint x, t_uint y, int color);
t_bool	window_free(t_window *w);
int		window_close(void *window);

// graphics/color.c
int		color_int(t_color *c);

// graphics/raytracing.c
void	raytracing(t_window *w, t_scene *s);

// graphics/ray.c
t_color	ray_color(t_ray *r, t_scene *s);

// graphics/camera.c
t_ray	camera_ray(t_camera *c, t_idx i, t_idx j);
t_bool	camera_change(t_camera *c, unsigned int key);

// graphics/ray_hits.c
t_bool	ray_hit_plane(const t_ray *r, const t_obj *p, float *t);
t_bool	ray_hit_sphere(const t_ray *r, const t_obj *s, float *t);
t_bool	ray_hit_cylinder(const t_ray *r, const t_obj *c);

#endif // MINIRT_H
