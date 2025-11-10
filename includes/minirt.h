/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:02:14 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/06 18:32:09 by mmichele         ###   ########.fr       */
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
# include <sys/time.h>

# include "libft.h"
# include "mlx.h"

# include "structs.h"
# include "parsing.h"

# define EPSILON 1e-3

/* MLX controller event codes */
# define WIN_CLOSE	17
# define K_ESC		65307

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
	t_luint		t;	// Contains the time of the last translation.
};

// events/mouse.c
int		mouse_handler(int key, int x, int y, struct s_ctx *c);

// events/key.c
int		key_handler(int key, struct s_ctx *ctx);

// events/loop.c
int		loop_handler(struct s_ctx *c);

// events/close.c
int		window_close(t_window *w);

// time.c
t_luint	time_now(void);

// graphics/window.c
t_bool	window_init(t_window *w);
void	window_draw(t_window *w, t_scene *s, void (*f)(t_window *, t_scene *));
void	window_draw_pixel(t_window *w, t_uint x, t_uint y, int color);
t_bool	window_free(t_window *w);

// graphics/color.c
int		color_int(t_color *c);

// graphics/raytracing.c
void	blurtracing(t_window *w, t_scene *s);
void	raytracing(t_window *w, t_scene *s);

// graphics/ray.c
t_obj	*get_closest_hit(const t_ray *r, float *closest_t, t_scene *s);
t_color	ray_color(t_ray *r, t_scene *s);

// graphics/camera.c
t_ray	camera_ray(t_camera *c, t_idx x, t_idx y);
void	camera_change(t_camera *c, unsigned int key);

// graphics/ray_hits.c
t_bool	ray_hit_sph(const t_ray *r, const t_obj *s, float *t);
t_bool	ray_hit_pla(const t_ray *r, const t_obj *p, float *t);
t_bool	ray_hit_cyl(const t_ray *r, const t_obj *cy, float *t);

// graphics/lights.c
t_color	ray_light_color(t_scene *s, t_ray *r, t_obj *hit_obj, float closest_t);

// maths/vec_utils.c
t_vec	vec_proj(const t_vec v, const t_vec w);
t_vec	vec_perp(const t_vec v, const t_vec w);
t_vec	vec_rot(const t_vec *v, const t_vec *w, const t_rad a);

// maths/eq2.c
t_eq2	eq2_init(const t_vec oc, const t_vec rdir, const float r);
void	eq2_set_delta(t_eq2 *e);

#endif // MINIRT_H
