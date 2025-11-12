#include "minirt.h"

t_bool	parse_optional_args(char **split, t_obj *obj)
{
	t_idx i;

	i = 0;
	while (split[i])
	{
		if (!split[i][0] || !split[i][1] || split[i][1] != '=')
			return (print_error("Invalid key=value format\n"), 0);
		if (split[i][0] == 'b')
			if (!parse_float(&split[i][2], &obj->brightness) || !check_frange(obj->brightness, 0.0, 1.0))
				return (print_error("Invalid brightness format\n"), 0);
		if (split[i][0] == 'r')
			if (!parse_float(&split[i][2], &obj->reflection) || !check_frange(obj->brightness, 0.0, 1.0))
				return (print_error("Invalid reflection format\n"), 0);
		if (split[i][0] == 'c')
		{
			if (ft_strcmp(&split[i][2], "1") == 0)
				obj->checkboard = 1;
			else if (ft_strcmp(&split[i][2], "0") == 0)
				return (print_error("Invalid checkboard format\n"), 0);
		}
		i++;
	}
	return (1);
}
