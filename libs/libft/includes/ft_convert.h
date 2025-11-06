/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:01:55 by mmichele          #+#    #+#             */
/*   Updated: 2025/10/29 22:14:38 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONVERT_H
# define FT_CONVERT_H

# include "libft.h"

int		ft_atoi_base(char *str, char *base);
t_bool	fts_atoi_base(long int *res, char *str, char *base);
int		ft_atoi(const char *nptr);
t_bool	fts_atoi(int *res, const char *s);
char	*ft_itoa(int n);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
void	ft_frombin(void *res, char *bin, const t_len len, \
	const t_bool little_endian);
void	ft_tobin(char *res, const void *mem, const t_size size, \
	const t_bool little_endian);
char	*ft_xtobin(const void *mem, const t_size size, \
	const t_bool little_endian);

#endif //FT_CONVERT_H