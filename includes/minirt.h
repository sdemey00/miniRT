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
# include <fcntl.h>
# include <sys/time.h>

# include "libft.h"
# include "mlx.h"

# include "structs.h"
# include "parsing.h"
# include "export.h"
# include "controller.h"

# define EPSILON 1e-2

/* MLX controller event codes */
# define WIN_CLOSE	17
# define K_ESC		65307
# define K_BS		65288
# define K_UP		65362
# define K_DOWN		65364

// Default optionnal obj args
# define DFLT_BRIGHT	32
# define DFLT_REFLECT	0
# define OPTION_ARGS	5

// parsing/parse_file.c
t_bool	filepath_has_rt(const char *fpath);

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
void	window_draw(struct s_ctx *c);
void	window_draw_pixel(t_window *w, t_uint x, t_uint y, int color);
t_bool	window_free(t_window *w);
void	window_clear(t_window *w);

// graphics/color.c
int		color_int(const t_color *c);

// graphics/raytracing.c
void	blurtracing(t_window *w, t_scene *s);
t_bool	full_render(struct s_ctx *c, const t_idx i);

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
t_vec	vec_fmin(const t_vec *v, const float f);

// maths/eq2.c
t_eq2	eq2_init(const t_vec oc, const t_vec rdir, const float r);
void	eq2_set(t_eq2 *e);

// graphics/normal.c
void	compute_tangent_space(t_hit *h);
t_vec	get_local_hit(t_hit *hitten, t_vec local_hit);
t_vec	get_surface_normal(t_obj *obj, t_vec hit_point);

// graphics/reflexion.c
t_color	compute_reflexion(t_ray *r, t_scene *s, t_hit *hitten, int depth);

// graphics/obj_change.c
void	obj_change(t_obj *o, struct s_ctx *c, const int key);

// graphics/map_uv.c
t_vec	map_obj(t_hit *hitten);

// graphics/xmp_tex.c
t_color	checkboard_pattern(t_hit *hitten);
t_bool	load_texture(t_tex *tex, void *mlx, char *path);
t_color	texture_color(t_tex *tex, t_hit *hitten);
int		get_tex_pixel(t_tex *tex, int x, int y);

// graphics/bump_tex.c
void	apply_bump(t_hit *h, float strength);

// bitmap.c
void	bitmap_switch(t_bitmap *b, const t_ssuint i);
t_bool	bitmap_get(const t_bitmap *b, const t_ssuint i);
void	bitmap_print(const t_bitmap *b);

// graphics/rasterizers.c
void	raster_linear(t_window *w, t_scene*s);
void	raster_evenly(t_window *w, t_scene *s);
void	raster_grid(t_window *w, t_scene *s);

#endif // MINIRT_H
