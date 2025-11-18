/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_optional_args.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:17:31 by sdemey            #+#    #+#             */
/*   Updated: 2025/11/13 16:05:42 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	parse_optional_args(char **split, t_obj *obj)
{
	t_idx	i;

	i = 0;
	while (split[i])
	{
		if (!split[i][0] || !split[i][1] || split[i][1] != '=')
			return (print_error("Invalid key=value format\n"), 0);
		if (split[i][0] == 's')
			if (!parse_int(&split[i][2], &obj->shininess) || \
				!check_frange(obj->shininess, 0, 320))
				return (print_error("Invalid shininess format\n"), 0);
		if (split[i][0] == 'r')
			if (!parse_float(&split[i][2], &obj->reflexion) || \
				!check_frange(obj->reflexion, 0.0, 1.0))
				return (print_error("Invalid reflexion format\n"), 0);
		if (split[i][0] == 'c')
		{
			if (ft_strcmp(&split[i][2], "1") == 0)
				bitmap_switch(&obj->effects, CHECKER_PATTERN);
			else if (ft_strcmp(&split[i][2], "0") != 0)
				return (print_error("Invalid checkboard format\n"), 0);
		}
		// if (split[i][0] == 'x')
		// {
		// //parse XPM
		// 	load_texture()
		// }
		i++;
	}
	return (1);
}
