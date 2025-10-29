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
	printf("////////////////////////////////////////\n");
	print_ambiant_infos(scene);
	printf("----------------------------------------\n");
	print_camera_infos(scene);
	printf("----------------------------------------\n");
	print_light_infos(scene);
	printf("----------------------------------------\n");
	print_spheres_infos(scene);
	printf("----------------------------------------\n");
	print_planes_infos(scene);
	printf("----------------------------------------\n");
	print_cylinders_infos(scene);
	printf("////////////////////////////////////////\n");
}
