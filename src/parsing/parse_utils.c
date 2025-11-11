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

void	ft_free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

t_bool	parse_float(char *src, float *out)
{
	if (!is_valid_float(src))
		return (0);
	*out = ft_atof(src);
	return (1);
}

t_bool	parse_int(char *src, int *out)
{
	if (!is_valid_int(src))
		return (0);
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
		print_error("Invalid vector format: invalid float format\n");
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
		print_error("Invalid color format: invalid float format\n");
		return (0);
	}
	if (!check_range_int(c->x, 0, 255, "Invalid color range [0, 255]\n")
		|| !check_range_int(c->y, 0, 255, "Invalid color range [0, 255]\n")
		|| !check_range_int(c->z, 0, 255, "Invalid color range [0, 255]\n"))
		return (ft_free_split(tab), 0);
	return (ft_free_split(tab), 1);
}
