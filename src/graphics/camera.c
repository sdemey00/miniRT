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

static t_vec	camera_space(t_camera *c, t_vec dir_cam)
{
	t_vec forward;
	t_vec world_up;
	t_vec right;
	t_vec up;
	t_vec temp;

	world_up = (t_vec){0, 1, 0};
	forward = vec_norm(&c->dir);
	temp = vec_cross(world_up, forward);
	right = vec_norm(&temp);
	up = vec_cross(forward, right);
	return (
		(t_vec){
			right.x * dir_cam.x + up.x * dir_cam.y + forward.x * dir_cam.z,
			right.y * dir_cam.x + up.y * dir_cam.y + forward.y * dir_cam.z,
			right.z * dir_cam.x + up.z * dir_cam.y + forward.z * dir_cam.z
		});
}

t_ray	camera_ray(t_camera *c, t_idx x, t_idx y)
{
	float	u;
	float	v;
	t_vec	world_dir;

	u = (2.0 * ((x + 0.5) / WIDTH) - 1.0) * RATIO * c->flen;
	v = (1.0 - 2.0 * ((y + 0.5) / HEIGHT)) * c->flen;
	world_dir = camera_space(c, (t_vec){u, v, -1.0});
	world_dir = vec_norm(&world_dir);
	return ((t_ray){c->pos, world_dir});
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
