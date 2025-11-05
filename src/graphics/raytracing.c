/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:31:38 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/04 17:59:50 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_ray get_ray(unsigned int i, unsigned int j, t_camera *c)
{
	const double	flen = tan(c->fov * FT_PI / 180 / 2);
    double			ratio = (double)WIDTH / HEIGHT;
    double			x = (2 * ((i + 0.5) / WIDTH) - 1) * ratio * flen;
    double			y = (1 - 2 * ((j + 0.5) / HEIGHT)) * flen;

	//printf("x before:%d\ty before:%d\n", i, j);
	//printf("x after:%f\ty after:%f\n", x, y);
	t_vec dir = (t_vec){x, y, -1}; // -1 ??
    //t_vec norm_dir = vec_norm(&dir);
    return ((t_ray){c->pos, dir});
}

t_color ray_color(t_ray r) 
{
	/*
	const t_sphere	sphere = (t_sphere){(t_vec){500, 100, 0}, 10, \
		(t_color){0, 128, 255}};
	const t_plane	plane = (t_plane){(t_vec){0, 0, 0}, \
		(t_vec){1, 1, 1}, (t_color){128, 0, 128}};
	*/
	t_obj sphere;
	sphere.pos = (t_vec){0.5,0,-5};
	sphere.radius = 1;
	sphere.color = (t_color){255,0,0};
	// t_obj plane;
	// plane.pos = (t_vec){0, 0, 0};
	// plane.dir = (t_vec){1, 1, 1};
	// plane.color = (t_color){128,0,128};
    if (ray_hit_sphere(&r, &sphere))
		return (sphere.color);
	// if (ray_hit_plane(&r, &plane))
    //     return (plane.color);
    return (t_color){135,206,235}; // fond bleu ciel
}

int	compute_lights(t_scene *s);
void	raytracing(t_window *w, t_scene *s)
{
	t_idx	x;
	t_idx	y;
	t_color	c;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c = ray_color(get_ray(x, y, &s->camera));
			window_draw_pixel(w, x, y, color_int(&c) * compute_lights(s));
			//window_draw_pixel(w, x, y, color_int(&c));
			x += 1;
		}
		y += 1;
	}
}
