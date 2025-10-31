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
	if (!split[1] || !split[2] || !split[3])
		return (ft_dprintf(2, "Camera: invalid number of arguments\n"), -1);
	if (!parse_vec(split[1], &cam.pos) || !parse_vec(split[2], &cam.dir))
		return (0);
	cam.fov = ft_atof(split[3]);
	if (!check_range_double(cam.fov, 0.0, 180.0, "Camera: FOV out of range\n")
		|| !check_range_int(cam.dir.x, -1, 1,
			"Camera: direction vector out of range [-1,1]\n")
		|| !check_range_int(cam.dir.y, -1, 1,
			"Camera: direction vector out of range [-1,1]\n")
		|| !check_range_int(cam.dir.z, -1, 1,
			"Camera: direction vector out of range [-1,1]\n"))
		return (0);
	scene->camera = cam;
	scene->camera.set = 1;
	return (1);
}

void	print_camera_infos(t_scene *scene)
{
	if (scene->camera.set != 1)
	{
		printf("There is no camera\n");
		return ;
	}
	printf("Camera position: %19.2f, %.2f, %.2f\n",
		scene->camera.pos.x, scene->camera.pos.y, scene->camera.pos.z);
	printf("Camera direction: %16.2f, %.2f, %.2f\n",
		scene->camera.dir.x, scene->camera.dir.y, scene->camera.dir.z);
	printf("Camera FOV: %23.2f\n", scene->camera.fov);
}
