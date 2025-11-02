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

t_bool	parse_float(char *str, char *out)
{
	if (!is_valid_float(str))
		return (0);
	*out = ft_atof(str);
	return (1);
}

t_bool	parse_int(char *str, int *out)
{
	if (!is_valid_int(str))
		return (0);
	*out = ft_atoi(str);
	return (1);
}
