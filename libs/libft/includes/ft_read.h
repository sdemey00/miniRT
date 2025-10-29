/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:36:37 by mmichele          #+#    #+#             */
/*   Updated: 2025/07/13 16:08:24 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READ_H
# define FT_READ_H

# include "libft.h"

char	*ft_gnl(int fd);
t_bool	fts_gnl(char **line, int fd);

#endif //FT_READ_H