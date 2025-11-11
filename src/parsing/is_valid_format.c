/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemey <sdemey@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:18:34 by sdemey            #+#    #+#             */
/*   Updated: 2025/11/04 14:18:36 by sdemey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	is_valid_int(char *s)
{
	if (!s || !*s)
		return (0);
	if (*s == '+' || *s == '-')
		s++;
	if (!ft_isdigit(*s))
		return (0);
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

t_bool	is_valid_float(char *s)
{
	int	dot;

	dot = 0;
	if (!s || !*s)
		return (0);
	if (*s == '+' || *s == '-')
		s++;
	while (*s)
	{
		if (*s == '.')
		{
			if (dot++)
				return (0);
		}
		else if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

t_bool	check_range_double(double val, double min, double max, char *msg)
{
	if (val < min || val > max)
		return (print_error(msg), 0);
	return (1);
}

t_bool	check_range_int(int val, int min, int max, char *msg)
{
	if (val < min || val > max)
		return (print_error(msg), 0);
	return (1);
}

t_bool	check_args_count(char **tab, const unsigned int count)
{
	t_idx	i;

	i = 0;
	while (tab[i])
		i++;
	if ((const unsigned int)i != count)
		return (0);
	return (1);
}
