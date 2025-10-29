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

void	check_range_double(double val, double min, double max, char *msg)
{
	if (val < min || val > max)
		ft_dprintf(2, msg);
}

void	check_range_int(int val, int min, int max, char *msg)
{
	if (val < min || val > max)
		ft_dprintf(2, msg);
}

t_vec	parse_vec(char *str)
{
	char	**tab;
	t_vec	v;

	tab = ft_split(str, ',');
	if (!tab[0] || !tab[1] || !tab[2])
		ft_dprintf(2, "Invalid vector format");
	v.x = ft_atof(tab[0]);
	v.y = ft_atof(tab[1]);
	v.z = ft_atof(tab[2]);
	ft_free_split(tab);
	return (v);
}

t_color	parse_color(char *str)
{
	char	**tab;
	t_color	c;

	tab = ft_split(str, ',');
	if (!tab[0] || !tab[1] || !tab[2])
		ft_dprintf(2, "Invalid color format");
	c.r = ft_atoi(tab[0]);
	c.g = ft_atoi(tab[1]);
	c.b = ft_atoi(tab[2]);
	check_range_int(c.r, 0, 255, "Invalid color range");
	check_range_int(c.g, 0, 255, "Invalid color range");
	check_range_int(c.b, 0, 255, "Invalid color range");
	ft_free_split(tab);
	return (c);
}
