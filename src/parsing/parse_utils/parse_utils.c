/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemey <sdemey@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:33:14 by sdemey            #+#    #+#             */
/*   Updated: 2025/10/29 12:33:16 by sdemey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	parse_float(char *src, float *out)
{
	if (!is_valid_float(src))
		return (print_error("Invalid float format\n"), 0);
	*out = ft_atof(src);
	return (1);
}

t_bool	parse_int(char *src, int *out)
{
	if (!is_valid_int(src))
		return (print_error("Invalid float format\n"), 0);
	*out = ft_atoi(src);
	return (1);
}

t_bool	parse_vec(char *str, t_vec *v)
{
	char	**tab;

	tab = ft_split(str, ',');
	if (!tab)
		return (0);
	if (!check_args_count(tab, 3))
	{
		ft_free_split(tab);
		print_error("Invalid vector format: invalid number of arguments\n");
		return (0);
	}
	if (!parse_float(tab[0], &v->x)
		|| !parse_float(tab[1], &v->y)
		|| !parse_float(tab[2], &v->z))
	{
		ft_free_split(tab);
		return (0);
	}
	ft_free_split(tab);
	return (1);
}

t_bool	parse_color(char *str, t_color *c)
{
	char	**tab;

	tab = ft_split(str, ',');
	if (!tab)
		return (0);
	if (!check_args_count(tab, 3))
	{
		ft_free_split(tab);
		print_error("Invalid color format: invalid number of arguments\n");
		return (0);
	}
	if (!parse_float(tab[0], &c->x) || !parse_float(tab[1], &c->y)
		|| !parse_float(tab[2], &c->z))
	{
		ft_free_split(tab);
		return (0);
	}
	if (!check_irange(c->x, 0, 255.0)
		|| !check_irange(c->y, 0, 255.0)
		|| !check_irange(c->z, 0, 255.0))
		return (ft_free_split(tab), 0);
	return (ft_free_split(tab), 1);
}

t_bool	parse_dir(char *str, t_vec *v)
{
	float	mag;

	if (!parse_vec(str, v))
		return (0);
	//if (!check_frange(v->x, -1, 1)
	//	|| !check_frange(v->y, -1, 1)
	//	|| !check_frange(v->z, -1, 1))
	//	return (0);
	mag = ft_abs(vec_mag(*v));
	if (mag < 0.9999 || 1.0001 < mag)
	{
		print_error("Direction vector is not normalized\n");
		return (0);
	}
	vec_inorm(v);
	return (1);
}
