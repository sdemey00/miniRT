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

t_bool	check_range_double(double val, double min, double max, char *msg)
{
	if (val < min || val > max)
		return (ft_dprintf(2, msg), 0);
	return (1);
}

t_bool	check_range_int(int val, int min, int max, char *msg)
{
	if (val < min || val > max)
		return (ft_dprintf(2, msg), 0);
	return (1);
}

t_bool	parse_vec(char *str, t_vec *v)
{
	char	**tab;

	tab = ft_split(str, ',');
	if (!tab[0] || !tab[1] || !tab[2])
	{
		ft_free_split(tab);
		return (ft_dprintf(2, "Invalid vector format\n"), 0);
	}
	v->x = ft_atof(tab[0]);
	v->y = ft_atof(tab[1]);
	v->z = ft_atof(tab[2]);
	ft_free_split(tab);
	return (1);
}

t_bool	parse_color(char *str, t_color *c)
{
	char	**tab;

	tab = ft_split(str, ',');
	if (!tab[0] || !tab[1] || !tab[2])
	{
		ft_free_split(tab);
		return (ft_dprintf(2, "Invalid color format\n"), -1);
	}
	c->x = ft_atoi(tab[0]);
	c->y = ft_atoi(tab[1]);
	c->z = ft_atoi(tab[2]);
	if (!check_range_int(c->x, 0, 255, "Invalid color range\n")
		|| !check_range_int(c->y, 0, 255, "Invalid color range\n")
		|| !check_range_int(c->z, 0, 255, "Invalid color range\n"))
	{
		ft_free_split(tab);
		return (0);
	}
	ft_free_split(tab);
	return (1);
}
