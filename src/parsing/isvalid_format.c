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
