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
		ft_dprintf(2, "Multiple camera definitions are not allowed\n");
		return (0);
	}
	if (!split[1] || !split[2] || !split[3] || split[4])
	{
		ft_dprintf(2, "Camera: invalid number of arguments\n");
		return (0);
	}
	if (!parse_vec(split[1], &cam.pos) || !parse_vec(split[2], &cam.dir))
		return (0);
	if (!parse_int(split[3], (int *)&cam.fov))
	{
		ft_dprintf(2, "Camera: FOV invalid int format\n");
		return (0);
	}
	if (!check_range_double(cam.fov, 0.0, 180.0, "Camera: FOV out of range\n")
		|| !check_range_int(cam.dir.x, -1, 1,
			"Camera: direction vector out of range [-1,1]\n")
		|| !check_range_int(cam.dir.y, -1, 1,
			"Camera: direction vector out of range [-1,1]\n")
		|| !check_range_int(cam.dir.z, -1, 1,
			"Camera: direction vector out of range [-1,1]\n"))
		return (0);
	if ((cam.dir.x == 0 && cam.dir.y == 0 && cam.dir.z == 0)
		|| (cam.dir.x == 1 && (cam.dir.y == 1 || cam.dir.z == 1))
		|| (cam.dir.z == 1 && (cam.dir.x == 1 || cam.dir.y == 1)))
	{
		ft_dprintf(2, "Camera: invalid direction vector\n");
		return (0);
	}
	scene->camera = cam;
	scene->camera.set = 1;
	return (1);
}

void	camera_print(t_scene *scene)
{
	if (scene->camera.set != 1)
	{
		printf("There is no camera\n");
		return ;
	}
	printf("Camera position: %.2f, %.2f, %.2f\n",
		scene->camera.pos.x, scene->camera.pos.y, scene->camera.pos.z);
	printf("Camera direction: %.2f, %.2f, %.2f\n",
		scene->camera.dir.x, scene->camera.dir.y, scene->camera.dir.z);
	printf("Camera FOV: %d\n", scene->camera.fov);
}
