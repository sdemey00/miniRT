/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_range.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemey <sdemey@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:17:10 by sdemey            #+#    #+#             */
/*   Updated: 2025/11/12 15:17:11 by sdemey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	check_frange(float val, float min, float max)
{
	if (val < min || val > max)
	{
		ft_dprintf(2, "Error\nInvalid direction float range [%.2f, %.2f]\n",
			min, max);
		return (0);
	}
	return (1);
}

t_bool	check_irange(int val, int min, int max)
{
	if (val < min || val > max)
	{
		ft_dprintf(2, "Error\nInvalid direction int range [%d, %d]\n",
			min, max);
		return (0);
	}
	return (1);
}

t_bool	check_vrange(t_vec *v, float min, float max)
{
	if (!check_frange(v->x, min, max)
		|| !check_frange(v->y, min, max)
		|| !check_frange(v->z, min, max))
	{
		ft_dprintf(2, "Invalid vector range\n");
		return (0);
	}
	return (1);
}

t_bool	check_args_count(char **tab, const t_uint count)
{
	t_idx	i;

	i = 0;
	while (tab[i])
		i++;
	if ((const unsigned int)i != count)
		return (0);
	return (1);
}

t_bool	check_args_range(char **tab, const t_uint min, const t_uint max)
{
	t_idx	i;

	i = 0;
	while (tab[i])
		i++;
	if ((const t_uint)i < min || (const t_uint)i > max)
		return (0);
	return (1);
}
