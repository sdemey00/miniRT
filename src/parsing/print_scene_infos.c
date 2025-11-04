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

void	print_error(char *msg)
{
	ft_dprintf(2, "Error\n");
	ft_dprintf(2, "%s", msg);
}

void	scene_print(t_scene *scene)
{
	ft_printf("________________________________________\n\n");
	ambiant_print(scene);
	ft_printf("________________________________________\n\n");
	camera_print(scene);
	ft_printf("________________________________________\n\n");
	lights_print(scene);
	ft_printf("________________________________________\n\n");
	spheres_print(scene);
	ft_printf("________________________________________\n\n");
	planes_print(scene);
	ft_printf("________________________________________\n\n");
	cylinders_print(scene);
	ft_printf("________________________________________\n");
}
