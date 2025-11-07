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

t_ray camera_ray(t_camera *c, t_idx i, t_idx j)
{
	float	x = (2 * ((i + 0.5) / WIDTH) - 1) * c->ratio * c->flen;
	float	y = (1 - 2 * ((j + 0.5) / HEIGHT)) * c->flen;

	t_vec temp = vec_cross((t_vec){0, 1, 0}, c->dir);
	t_vec right = vec_norm(&temp);
	t_vec up = vec_cross(c->dir, right);
	t_vec dir_cam = {x, y, 1}; // -1??
	t_vec dir = vec_norm(&(
		(t_vec){
			right.x * dir_cam.x + up.x * dir_cam.y + c->dir.x * dir_cam.z,
			right.y * dir_cam.x + up.y * dir_cam.y + c->dir.y * dir_cam.z,
			right.z * dir_cam.x + up.z * dir_cam.y + c->dir.z * dir_cam.z
		}
	));
	return ((t_ray){c->pos, dir});
}


static void	camera_translate(t_camera *c, unsigned int key)
{
	//const t_vec	right = vec_roty(c->dir, -FT_PI / 2);
	//const t_vec up = vec_rotx(c->dir, -FT_PI / 2);

	t_vec right = {1, 0, 0};
	t_vec up = {0, 1, 0};
	if (key == 'w')
		vec_isum(&c->pos, c->dir);
	else if (key == 's')
		vec_isub(&c->pos, c->dir);
	else if (key == 'd')
		vec_isum(&c->pos, right);
	else if (key == 'a')
		vec_isub(&c->pos, right);
	else if (key == ' ')
		vec_isum(&c->pos, up);
	else if (key == 'c')
		vec_isub(&c->pos, up);
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
	if (ft_strchr("wsda c", key) >= 0)
		camera_translate(c, key);
	else if (ft_strchr("ouiklj", key) >= 0)
		camera_rotate(c, key);
}
