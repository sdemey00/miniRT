/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:48:44 by mmichele          #+#    #+#             */
/*   Updated: 2025/05/30 22:08:26 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHAR_H
# define FT_CHAR_H

# include "libft.h"

t_bool	ft_isalnum(const char c);
t_bool	ft_isalpha(const char c);
t_bool	ft_isdigit(const char c);
t_bool	ft_islower(const char c);
t_bool	ft_issign(const char c);
t_bool	ft_isspace(const char c);
t_bool	ft_isupper(const char c);
char	ft_tolower(const char c);
char	ft_toupper(const char c);

#endif //FT_CHAR_H
