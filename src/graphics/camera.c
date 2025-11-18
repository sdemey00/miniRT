/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemey <sdemey@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:56:58 by sdemey            #+#    #+#             */
/*   Updated: 2025/11/06 18:35:29 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	camera_ray(t_camera *c, t_idx x, t_idx y)
{
	const float	u = (2.0 * ((x + 0.5) / WIDTH) - 1.0) * c->ratio * c->flen;
	const float	v = (1.0 - 2.0 * ((y + 0.5) / HEIGHT)) * c->flen;
	const t_vec	cam_dir = (t_vec){u, v, 1.0};
	t_vec		ray_dir;

	c->right = vec_cross((t_vec){0, 1, 0}, c->dir);
	vec_inorm(&c->right);
	c->up = vec_cross(c->dir, c->right);
	vec_inorm(&c->up);
	ray_dir = (t_vec){
		c->right.x * cam_dir.x + c->up.x * cam_dir.y + c->dir.x * cam_dir.z,
		c->right.y * cam_dir.x + c->up.y * cam_dir.y + c->dir.y * cam_dir.z,
		c->right.z * cam_dir.x + c->up.z * cam_dir.y + c->dir.z * cam_dir.z
	};
	vec_inorm(&ray_dir);
	return ((t_ray){c->pos, ray_dir});
}

static void	camera_translate(t_camera *c, const int key)
{
	if (key == 'w')
		vec_isum(&c->pos, vec_scal(c->dir, 0.5));
	else if (key == 's')
		vec_isub(&c->pos, vec_scal(c->dir, 0.5));
	else if (key == 'd')
		vec_isum(&c->pos, vec_scal(c->right, 0.5));
	else if (key == 'a')
		vec_isub(&c->pos, vec_scal(c->right, 0.5));
	else if (key == ' ')
		vec_isum(&c->pos, vec_scal((t_vec){0, 1, 0}, 0.25));
	else if (key == 'c')
		vec_isub(&c->pos, vec_scal((t_vec){0, 1, 0}, 0.25));
}

static void	camera_rotate(t_camera *c, const int key)
{
	const float	angle = FT_PI / 17;

	if (key == 'i')
		c->dir = vec_rot(&c->dir, &c->right, -angle);
	else if (key == 'k')
		c->dir = vec_rot(&c->dir, &c->right, angle);
	else if (key == 'l')
		vec_iroty(&c->dir, angle);
	else if (key == 'j')
		vec_iroty(&c->dir, -angle);
}

static void	camera_change_fov(t_camera *c, t_bool zoom_in)
{
	if (zoom_in)
	{
		if (c->fov > 0)
			c->fov--;
	}
	else
	{
		if (c->fov < 180)
			c->fov++;
	}
	c->flen = tan(c->fov * FT_PI / 180 / 2);
}

void	camera_change(struct s_ctx *c, const int key)
{
	if (ft_strchr("wasdc ", key) >= 0)
		camera_translate(&c->s.camera, key);
	else if (ft_strchr("ijkl", key) >= 0)
		camera_rotate(&c->s.camera, key);
	else if (ft_strchr("-=", key) >= 0)
		camera_change_fov(&c->s.camera, key == '=');
	if (VERBOSE)
		camera_print(&c->s.camera);
}
