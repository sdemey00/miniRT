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

# ifdef MAX_OBJS
#  if MAX_OBJS < 1 || 512 < MAX_OBJS
#   undef MAX_OBJS
#  endif
# endif
# ifndef MAX_OBJS
#  define MAX_OBJS 16
# endif

# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/time.h>

# include "libft.h"
# include "mlx.h"

# include "structs.h"
# include "parsing.h"

# define EPSILON 1e-4

/* MLX controller event codes */
# define WIN_CLOSE	17
# define K_ESC		65307
# define K_BS		65288
# define K_UP		65362
# define K_DOWN		65364

// Default optionnal obj args
# define DFLT_BRIGHT 0.4
# define DFLT_REFLECT 0
# define OPTION_ARGS 3

/* MLX pixel grid manipulation */
typedef struct s_image
{
	void	*ptr;
	char	*address;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_image;

/* Graphical library context -> MLX */
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
	t_bool		rendering;
};

typedef struct s_hit
{
	t_obj	*obj;
	float	dist;
	t_vec	point;
	t_vec	normal;
	t_vec	uv;
}	t_hit;

// graphics/t_hit.c

// events/mouse.c
int		mouse_press(int key, int x, int y, struct s_ctx *c);

// events/key.c
int		key_release(int key, struct s_ctx *c);

// events/window.c
int		window_close(t_window *w);

// time.c
double	time_now(void);

// graphics/window.c
t_bool	window_init(t_window *w);
void	window_draw(t_window *w, t_scene *s);
void	window_draw_pixel(t_window *w, t_uint x, t_uint y, int color);
t_bool	window_free(t_window *w);

// graphics/color.c
int		color_int(const t_color *c);

// graphics/raytracing.c
void	raytracing(t_window *w, t_scene *s, const t_suint blur);
int		full_render(struct s_ctx *c);

// graphics/ray.c
t_hit	get_closest_hit(const t_ray *r, t_scene *s);
t_color	ray_color(t_ray *r, t_scene *s, int depth);

// graphics/camera.c
t_ray	camera_ray(t_camera *c, t_idx x, t_idx y);
void	camera_change(struct s_ctx *c, const int key);

// graphics/ray_hits.c
t_bool	ray_hit_sph(const t_ray *r, const t_obj *s, float *t);
t_bool	ray_hit_pla(const t_ray *r, const t_obj *p, float *t);
t_bool	ray_hit_cir(const t_ray *r, const t_obj *ci, float *t);
t_bool	ray_hit_con(const t_ray *r, const t_obj *cy, float *t);

// graphics/ray_hit_cyl.c
t_bool	ray_hit_cyl(const t_ray *r, const t_obj *cy, float *t);

// graphics/lights.c
t_color	compute_lights(t_scene *s, t_hit *hitten, t_ray *r);

// maths/vec_utils.c
t_vec	vec_proj(const t_vec v, const t_vec w);
t_vec	vec_perp(const t_vec v, const t_vec w);
t_vec	vec_rot(const t_vec *v, const t_vec *w, const t_rad a);
void	vec_fmin(t_vec *v, float f);

// maths/eq2.c
t_eq2	eq2_init(const t_vec oc, const t_vec rdir, const float r);
void	eq2_set(t_eq2 *e);

// graphics/reflection.c
t_vec	get_surface_normal(t_obj *obj, t_vec hit_point);
t_color	compute_reflection(t_ray *r, t_scene *s, t_hit *hitten, int depth);

// graphics/shadows.c
t_bool	is_in_shadow(t_scene *s, t_vec hit_point, t_vec normal, t_light light);

// graphics/checkboard_pattern.c
t_color	checkboard_pattern(t_obj *obj, t_vec hit_point);

// graphics/obj_change.c
void	obj_change(t_obj *o, struct s_ctx *c, const int key);

void	map_sphere(float *u, float *v, t_vec hit_point);

#endif // MINIRT_H