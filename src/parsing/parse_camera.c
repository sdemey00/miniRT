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

static t_bool	check_camera_ranges(t_camera cam)
{
	if (!check_range_double(cam.fov, 0.0, 180.0, "Camera: FOV out of range\n")
		|| !check_range_int(cam.dir.x, -1, 1,
			"Camera: direction vector out of range [-1,1]\n")
		|| !check_range_int(cam.dir.y, -1, 1,
			"Camera: direction vector out of range [-1,1]\n")
		|| !check_range_int(cam.dir.z, -1, 1,
			"Camera: direction vector out of range [-1,1]\n"))
		return (0);
	if (cam.dir.x == 0 && cam.dir.y == 0 && cam.dir.z == 0)
	{
		print_error("Camera: invalid direction vector\n");
		return (0);
	}
	return (1);
}

t_bool	parse_camera(char **split, t_scene *scene)
{
	t_camera	cam;

	if (scene->camera.set)
	{
		print_error("Multiple camera definitions are not allowed\n");
		return (0);
	}
	if (!split[1] || !split[2] || !split[3] || split[4])
	{
		print_error("Camera: invalid number of arguments\n");
		return (0);
	}
	if (!parse_vec(split[1], &cam.pos) || !parse_vec(split[2], &cam.dir))
		return (0);
	if (!parse_int(split[3], (int *)&cam.fov))
	{
		print_error("Camera: FOV invalid int format\n");
		return (0);
	}
	if (!check_camera_ranges(cam))
		return (0);
	scene->camera = cam;
	scene->camera.set = 1;
	return (1);
}

void	camera_print(t_camera camera)
{
	if (camera.set != 1)
	{
		ft_printf("There is no camera\n");
		return ;
	}
	ft_printf("Camera position: %.2f, %.2f, %.2f\n",
		camera.pos.x, camera.pos.y, camera.pos.z);
	ft_printf("Camera direction: %.2f, %.2f, %.2f\n",
		camera.dir.x, camera.dir.y, camera.dir.z);
	ft_printf("Camera FOV: %d\n", camera.fov);
}
