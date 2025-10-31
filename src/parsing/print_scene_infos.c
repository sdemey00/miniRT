/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemey <sdemey@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:33:17 by sdemey            #+#    #+#             */
/*   Updated: 2025/10/29 12:33:19 by sdemey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_scene_infos(t_scene *scene)
{
	printf("________________________________________\n\n");
	print_ambiant_infos(scene);
	printf("________________________________________\n\n");
	print_camera_infos(scene);
	printf("________________________________________\n\n");
	print_lights_infos(scene);
	printf("________________________________________\n\n");
	print_spheres_infos(scene);
	printf("________________________________________\n\n");
	print_planes_infos(scene);
	printf("________________________________________\n\n");
	print_cylinders_infos(scene);
	printf("________________________________________\n");
}
