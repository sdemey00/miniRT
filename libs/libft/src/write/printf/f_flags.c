/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_flags.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:12:46 by mmichele          #+#    #+#             */
/*   Updated: 2025/10/29 16:12:38 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_printf.h"
#include "libft.h"

static unsigned int	custom_atoi(const char *s, size_t *i)
{
	unsigned int	res;
	unsigned int	numlen;

	numlen = 0;
	while ('0' <= s[(*i) + numlen] && s[(*i) + numlen] <= '9')
		numlen++;
	res = 0;
	while (numlen > 0)
		res += ft_pow(10, --numlen) * (s[(*i)++] - '0');
	return (res);
}

static size_t	set_base_case(t_flags *flags, t_idxstr *is)
{
	flags->format = '%';
	return (is->i);
}

size_t	t_flags_init(t_flags *flags, t_idxstr *is, int fd)
{
	const char	*map = " +#-0";

	ft_bzero(flags, sizeof(t_flags));
	flags->fd = fd;
	if (is->s[is->i] == '%')
		return (set_base_case(flags, is));
	while (is->s[is->i] && ft_strchr("cspdiuxXf", is->s[is->i]) < 0 && \
	ft_strchr(map, is->s[is->i]) >= 0)
	{
		flags->map[ft_strchr(map, is->s[is->i])] = 1;
		is->i++;
	}
	if ('1' <= is->s[is->i] && is->s[is->i] <= '9')
		flags->padding = custom_atoi(is->s, &is->i);
	if (is->s[is->i] == '.')
	{
		is->i += ++flags->map[E_DOT];
		flags->precision = custom_atoi(is->s, &is->i);
	}
	flags->format = is->s[is->i];
	if (ft_strchr("cspdiuxX%f", is->s[is->i]) < 0)
		return (0);
	return (is->i);
}
