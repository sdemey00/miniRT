#include "minirt.h"

static t_bool	is_valid_int(char *s)
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

static t_bool	is_valid_float(char *s)
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
