/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:56:58 by mmichele          #+#    #+#             */
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

	c->right = vec_cross(SPACE_UP, c->dir);
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

static void	camera_translate(t_camera *c, unsigned int key)
{
	if (key == 'w')
		vec_isum(&c->pos, c->dir);
	else if (key == 's')
		vec_isub(&c->pos, c->dir);
	else if (key == 'd')
		vec_isum(&c->pos, c->right);
	else if (key == 'a')
		vec_isub(&c->pos, c->right);
	else if (key == ' ')
		vec_isum(&c->pos, SPACE_UP);
	else if (key == 'c')
		vec_isub(&c->pos, SPACE_UP);
}

static void	camera_rotate(t_camera *c, unsigned int key)
{
	const float	angle = FT_PI / 16;

	// TODO Bound the max and min of direction vector when looking up or down.
	if (key == 'i')
	{
		c->dir = vec_rot(&c->dir, &c->right, -angle);
	}
	else if (key == 'k')
	{
		c->dir = vec_rot(&c->dir, &c->right, angle);
	}
	else if (key == 'l')
		vec_iroty(&c->dir, angle);
	else if (key == 'j')
		vec_iroty(&c->dir, -angle);
	vec_inorm(&c->dir);
}

void	camera_change(t_camera *c, unsigned int key)
{
	if (VERBOSE)
		camera_print(*c);
	if (ft_strchr("wsda c", key) >= 0)
		camera_translate(c, key);
	else if (ft_strchr("iklj", key) >= 0)
		camera_rotate(c, key);
}
