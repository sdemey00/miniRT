/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmp.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 21:00:00 by mmichele          #+#    #+#             */
/*   Updated: 2025/06/18 22:43:21 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CMP_H
# define FT_CMP_H

# include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, const t_size size);
t_sign	ft_vpfltcmp(const void *v1, const void *v2);
t_sign	ft_vpintcmp(const void *v1, const void *v2);
t_sign	ft_vpstrcmp(const void *s1, const void *s2);

#endif // FT_CMP_H
