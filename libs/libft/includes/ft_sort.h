/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 19:24:41 by mmichele          #+#    #+#             */
/*   Updated: 2025/06/06 20:50:03 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SORT_H
# define FT_SORT_H

# include "libft.h"

t_bool	ft_insertion_sort(void *mem, t_size unit, t_len len, \
	t_sign (*cmp)(const void *, const void *));
t_bool	ft_selection_sort(void *mem, t_size unit, t_len len, \
	t_sign (*cmp)(const void *, const void *));

#endif // FT_SORT_H
