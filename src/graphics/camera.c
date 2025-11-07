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

static t_vec	camera_space(t_camera *c, t_vec cam_dir)
{
	const t_vec world_up = (t_vec){0, 1, 0};
	t_vec forward;
	t_vec right;
	t_vec up;

	forward = vec_norm(&c->dir); //si pas de vec_norm -> bug fov
	right = vec_cross(world_up, forward);
	up = vec_cross(forward, right);
	return ((t_vec){
			right.x * cam_dir.x + up.x * cam_dir.y + forward.x * cam_dir.z,
			right.y * cam_dir.x + up.y * cam_dir.y + forward.y * cam_dir.z,
			right.z * cam_dir.x + up.z * cam_dir.y + forward.z * cam_dir.z
		});
}

t_ray	camera_ray(t_camera *c, t_idx x, t_idx y)
{
	float	u;
	float	v;
	t_vec	space_dir;

	u = (2.0 * ((x + 0.5) / WIDTH) - 1.0) * RATIO * c->flen;
	v = (1.0 - 2.0 * ((y + 0.5) / HEIGHT)) * c->flen;
	space_dir = camera_space(c, (t_vec){u, v, -1.0});
	space_dir = vec_norm(&space_dir);
	return ((t_ray){c->pos, space_dir});
}

static void	camera_translate(t_camera *c, unsigned int key)
{
	if (key == 's')
		vec_isub(&c->pos, c->dir);
	else if (key == 'w')
		vec_isum(&c->pos, c->dir);
	else if (key == 'a')
		c->pos.x -= 1;
	else if (key == 'd')
		c->pos.x += 1;
	else if (key == ' ')
		c->pos.z -= 1;
	else if (key == 'c')
		c->pos.z += 1;
}

static void	camera_rotate(t_camera *c, unsigned int key)
{
	if (key == 'o')
		c->dir.z -= 1 - 0.5;
	else if (key == 'u')
		c->dir.z += 1 - 0.5;
	else if (key == 'i')
		c->dir.y -= 1 - 0.5;
	else if (key == 'k')
		c->dir.y += 1 - 0.5;
	else if (key == 'l')
		c->dir.x -= 1 - 0.5;
	else if (key == 'j')
		c->dir.x += 1 - 0.5;
}

void	camera_change(t_camera *c, unsigned int key)
{
	if (ft_strchr("qweasd", key) >= 0)
		camera_translate(c, key);
	else if (ft_strchr("uiojkl", key) >= 0)
		camera_rotate(c, key);
}
