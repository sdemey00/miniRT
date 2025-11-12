/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_background.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemey <sdemey@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:17:21 by sdemey            #+#    #+#             */
/*   Updated: 2025/11/12 15:17:23 by sdemey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	parse_bg(char **split, t_scene *scene)
{
	if (scene->bg_set)
	{
		print_error("Multiple background definitions are not allowed\n");
		return (0);
	}
	if (!check_args_count(split, 1))
	{
		print_error("Background: invalid number of arguments\n");
		return (0);
	}
	if (!parse_color(split[0], &scene->bg))
		return (0);
	scene->bg_set = 1;
	return (1);
}