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

static t_bool	parse_checkboard(char *split, t_obj *obj)
{
	if (ft_strcmp(&split[2], "1") == 0)
		bitmap_switch(&obj->effects, CHECKER_PATTERN);
	else if (ft_strcmp(&split[2], "0") != 0)
		return (print_error("Invalid checkboard format\n"), 0);
	return (1);
}

static t_bool	parse_bump(char *split, t_obj *obj, void *mlx)
{
	const char	*ext = ft_strrchr(&split[2], '.');

	if (ext && ft_strcmp(ext, ".xpm") == 0)
	{
		obj->bump.e_type = XPM_BUMP;
		if (!load_texture(&obj->bump.texture, mlx, &split[2]))
			return (print_error("XPM file loading failed\n"), 0);
	}
	else if (ft_strcmp(&split[2], "tex") == 0)
		obj->bump.e_type = XPM_TEX;
	else if (ft_strcmp(&split[2], "1") == 0)
		obj->bump.e_type = PROC_WAVE;
	else if (ft_strcmp(&split[2], "0") != 0)
		return (print_error("Invalid bump format\n"), 0);
	return (1);
}

t_bool	parse_optional_args(char **split, t_obj *obj, void *mlx)
{
	t_idx	i;

	i = 0;
	while (split[i])
	{
		if (!split[i][0] || !split[i][1] || split[i][1] != '=')
			return (print_error("Invalid key=value format\n"), 0);
		if (ft_strchr("srcxb", split[i][0]) == -1)
			return (print_error("Unknown identifier\n"), 0);
		if (split[i][0] == 's' && (!parse_int(&split[i][2], &obj->shininess)
				|| !check_frange(obj->shininess, 0, 320)))
			return (print_error("Invalid shininess format\n"), 0);
		if (split[i][0] == 'r' && (!parse_float(&split[i][2], &obj->reflexion)
				|| !check_frange(obj->reflexion, 0.0, 1.0)))
			return (print_error("Invalid reflexion format\n"), 0);
		if (split[i][0] == 'c' && !parse_checkboard(split[i], obj))
			return (0);
		if (split[i][0] == 'x'
			&& !load_texture(&obj->texture, mlx, &split[i][2]))
			return (print_error("XPM file loading failed\n"), 0);
		if (split[i][0] == 'b' && !parse_bump(split[i], obj, mlx))
			return (0);
		i++;
	}
	return (1);
}
