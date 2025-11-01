/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:57:09 by mmichele          #+#    #+#             */
/*   Updated: 2025/08/05 21:46:08 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_aec_print(t_aec aec, const char *str, const t_bool newline)
{
	const char	aec_str[11] = "\e[0;30;40m";

	((char *)aec_str)[2] += (unsigned int)aec.sty;
	((char *)aec_str)[5] += (unsigned int)aec.fg;
	((char *)aec_str)[8] += (unsigned int)aec.bg;
	ft_printf("%s%s\e[0m", aec_str, str);
	if (newline)
		ft_printf("\n");
	return (1);
}

char	*ft_aec_str(t_aec aec, const char *str, const t_bool newline)
{
	const char		*begin = "\001\e[0;30;40m\002";
	const char		*end = "\001\e[0m\002";
	const t_len		slen = ft_strlen(str);
	char			*res;

	if (!fts_malloc((void **)&res, 19 + slen + !!newline))
		return (0);
	ft_memcpy(res, begin, 12);
	res[3] += (unsigned int)aec.sty;
	res[6] += (unsigned int)aec.fg;
	res[9] += (unsigned int)aec.bg;
	ft_memcpy(res + 12, str, slen);
	ft_memcpy(res + 12 + slen, end, 6);
	if (newline)
		res[17 + slen + 1] = '\n';
	res[18 + slen + !!newline] = 0;
	return (res);
}
