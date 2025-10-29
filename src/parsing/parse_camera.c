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

void	parse_camera(char **split, t_scene *scene)
{
	t_camera	cam;

	if (scene->camera.set)
		ft_dprintf(2, "Multiple camera definitions are not allowed");
	if (!split[1] || !split[2] || !split[3])
		ft_dprintf(2, "Camera: invalid number of arguments");
	cam.pos = parse_vec(split[1]);
	cam.dir = parse_vec(split[2]);
	cam.fov = ft_atof(split[3]);
	check_range_double(cam.fov, 0.0, 180.0, "Camera: FOV out of range");
	check_range_int(cam.dir.x, -1, 1,
		"Camera: direction vector out of range [-1,1]");
	check_range_int(cam.dir.y, -1, 1,
		"Camera: direction vector out of range [-1,1]");
	check_range_int(cam.dir.z, -1, 1,
		"Camera: direction vector out of range [-1,1]");
	scene->camera = cam;
	scene->camera.set = 1;
}

void	print_camera_infos(t_scene *scene)
{
	printf("Camera position: %.2f, %.2f, %.2f\n",
		scene->camera.pos.x, scene->camera.pos.y, scene->camera.pos.z);
	printf("Camera direction: %.2f, %.2f, %.2f\n",
		scene->camera.dir.x, scene->camera.dir.y, scene->camera.dir.z);
	printf("Camera FOV: %.2f\n", scene->camera.fov);
}
