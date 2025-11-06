/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:56:14 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/01 15:56:15 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	scene_init(t_scene *scene)
{
	scene->ambiant.set = 0;
	scene->camera.set = 0;
	scene->lights_len = 0;
	scene->objs_len = 0;
}
