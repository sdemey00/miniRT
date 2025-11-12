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

void	objs_print(t_obj *objs, t_ssuint objs_len)
{
	int	i;

	i = 0;
	while (i < objs_len)
	{
		if (objs[i].e_type == SPH)
			sphere_print(&objs[i]);
		if (objs[i].e_type == PLA)
			plane_print(&objs[i]);
		if (objs[i].e_type == CYL)
			cylinder_print(&objs[i]);
		if (objs[i].e_type == CON)
			cone_print(&objs[i]);
		if (objs[i].e_type == CIR)
			circle_print(&objs[i]);
		if (i < objs_len - 1)
			ft_printf("- - - - - - - - - - - - - - - - - - - -\n");
		i++;
	}
}

void	scene_print(t_scene *scene)
{
	ft_printf("________________________________________\n\n");
	ambiant_print(&scene->ambiant);
	ft_printf("________________________________________\n\n");
	camera_print(&scene->camera);
	ft_printf("________________________________________\n\n");
	lights_print(scene->lights, scene->lights_len);
	ft_printf("________________________________________\n\n");
	objs_print(scene->objs, scene->objs_len);
	ft_printf("________________________________________\n\n");
}
