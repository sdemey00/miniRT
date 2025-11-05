/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 10:30:30 by mmichele          #+#    #+#             */
/*   Updated: 2025/08/03 18:50:14 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_sign	f_check_sign(const char *s, t_idx *i)
{
	t_sign	res;

	res = 1;
	if (ft_issign(s[*i]))
	{
		if (s[*i] == '-')
			res = -1;
		(*i)++;
	}
	return (res);
}

static t_len	f_numlen(const char *str)
{
	t_len	res;

	res = 0;
	while (ft_isdigit(str[res]))
		res++;
	return (res);
}

static t_bool	f_check_int_overflow(const char *s, t_len *res, t_sign sign)
{
	t_len		len;

	*res = f_numlen(s);
	len = ft_strlen(s);
	if (*res != len || len > 10)
		return (0);
	else if (len == 10)
	{
		if ((sign > 0 && ft_strcmp(s, "2147483647") > 0) || \
			(sign < 0 && ft_strcmp(s, "2147483648") > 0))
			return (0);
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	t_idx			i;
	t_sign			sign;
	unsigned int	res;
	unsigned int	numlen;

	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	sign = f_check_sign(nptr, &i);
	numlen = f_numlen(&nptr[i]);
	res = 0;
	while (numlen > 0)
	{
		res += ft_pow(10, numlen - 1) * (nptr[i] - '0');
		numlen--;
		i++;
	}
	return (sign * res);
}

t_bool	fts_atoi(int *res, const char *s)
{
	t_sign		sign;
	t_len		len;
	t_idx		i;

	i = 0;
	sign = f_check_sign(s, &i);
	if (!f_check_int_overflow(&s[i], &len, sign))
		return (0);
	*res = 0;
	while (len > 0)
	{
		*res += (sign * ft_pow(10, len - 1) * (s[i] - '0'));
		len--;
		i++;
	}
	return (1);
}
