#include "minirt.h"

t_bool	check_frange(float val, float min, float max)
{
	if (val < min || val > max)
		return (ft_dprintf(2, "Error\nInvalid direction float range [%.2f, %.2f]\n", min, max), 0);
	return (1);
}

t_bool	check_irange(int val, int min, int max)
{
	if (val < min || val > max)
		return (ft_dprintf(2, "Error\nInvalid direction int range [%d, %d]\n", min, max), 0);
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

t_bool	check_args_range(char **tab, const unsigned int min, const unsigned int max)
{
	t_idx	i;

	i = 0;
	while (tab[i])
		i++;
	if ((const unsigned int)i < min || (const unsigned int)i > max)
		return (0);
	return (1);
}