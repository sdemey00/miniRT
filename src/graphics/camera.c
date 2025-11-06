/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:56:58 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/05 18:14:32 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray camera_ray(t_camera *c, t_idx i, t_idx j)
{
	const double	flen = tan(c->fov * FT_PI / 180 / 2);
	const double	ratio = (double)WIDTH / HEIGHT;
	double			x = (2 * ((i + 0.5) / WIDTH) - 1) * ratio * flen;
	double			y = (1 - 2 * ((j + 0.5) / HEIGHT)) * flen;

	t_vec forward = vec_norm(&c->dir);
	t_vec world_up = {0, 1, 0};
	t_vec temp = vec_cross(world_up, forward);
	t_vec right = vec_norm(&temp);
	t_vec up = vec_cross(forward, right);
	//printf("x before:%d\ty before:%d\n", i, j);
	//printf("x after:%f\ty after:%f\n", x, y);
	t_vec dir_cam = {x, y, -1}; // -1??
	t_vec dir = vec_norm(&(
		(t_vec){
			right.x * dir_cam.x + up.x * dir_cam.y + forward.x * dir_cam.z,
			right.y * dir_cam.x + up.y * dir_cam.y + forward.y * dir_cam.z,
			right.z * dir_cam.x + up.z * dir_cam.y + forward.z * dir_cam.z
		}
	));
	//t_vec norm_dir = vec_norm(&dir); --> matrice de rotation
	return ((t_ray){c->pos, dir});
}


static void	camera_translate(t_camera *c, unsigned int key)
{
	if (key == 'q')
		c->pos.z -= MOVE_SPEED;
	else if (key == 'e')
		c->pos.z += MOVE_SPEED;
	else if (key == 's')
		c->pos.y -= MOVE_SPEED;
	else if (key == 'w')
		c->pos.y += MOVE_SPEED;
	else if (key == 'a')
		c->pos.x -= MOVE_SPEED;
	else if (key == 'd')
		c->pos.x += MOVE_SPEED;
}

static void	camera_rotate(t_camera *c, unsigned int key)
{
	if (key == 'u')
		c->dir.z -= MOVE_SPEED;
	else if (key == 'o')
		c->dir.z += MOVE_SPEED;
	else if (key == 'k')
		c->dir.y -= MOVE_SPEED;
	else if (key == 'i')
		c->dir.y += MOVE_SPEED;
	else if (key == 'j')
		c->dir.x -= MOVE_SPEED;
	else if (key == 'l')
		c->dir.x += MOVE_SPEED;
}

t_bool	camera_change(t_camera *c, unsigned int key)
{
	if (ft_strchr("qweasd", key) >= 0)
		camera_translate(c, key);
	else if (ft_strchr("uiojkl", key) >= 0)
		camera_rotate(c, key);
	return (1);
}
