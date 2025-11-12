/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemey <sdemey@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:32:30 by sdemey            #+#    #+#             */
/*   Updated: 2025/10/29 12:32:32 by sdemey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	parse_camera(char **split, t_scene *scene)
{
	t_camera	cam;

	if (scene->camera.set)
	{
		print_error("Multiple camera definitions are not allowed\n");
		return (0);
	}
	if (!check_args_count(split, 3))
	{
		print_error("Camera: invalid number of arguments\n");
		return (0);
	}
	if (!parse_vec(split[0], &cam.pos)
		|| !parse_dir(split[1], &cam.dir)
		|| !parse_int(split[2], (int *)&cam.fov))
		return (0);
	scene->camera = cam;
	scene->camera.set = 1;
	return (1);
}

void	camera_print(const t_camera *camera)
{
	if (camera->set != 1)
	{
		ft_printf("There is no camera\n");
		return ;
	}
	ft_printf("Camera position: %.2f, %.2f, %.2f\n",
		camera->pos.x, camera->pos.y, camera->pos.z);
	ft_printf("Camera direction: %.2f, %.2f, %.2f\n",
		camera->dir.x, camera->dir.y, camera->dir.z);
	ft_printf("Camera FOV: %d\n", camera->fov);
}
