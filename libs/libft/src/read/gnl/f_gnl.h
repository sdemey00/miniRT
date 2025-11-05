/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_gnl.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 23:36:21 by mmichele          #+#    #+#             */
/*   Updated: 2025/07/15 17:56:15 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_GNL_H
# define F_GNL_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifdef BUFFER_SIZE
#  if BUFFER_SIZE < 1 || BUFFER_SIZE > INT_MAX
#   undef BUFFER_SIZE
#  endif
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif //BUFFER_SIZE

# define MAX_FILES 8		// ulimit -n

# define STR_INIT_SIZE 32
# define STR_SCALE 2

typedef unsigned char	t_bool;

typedef struct s_buf
{
	size_t	len;
	char	data[BUFFER_SIZE + 1];
}	t_buf;

typedef struct s_str
{
	size_t	size;	// Current number of bytes allocated.
	size_t	len;	// Current number of used bytes.
	char	*data;	// String.
}	t_str;

char	*str_free(t_str *s);
t_bool	str_read(t_str *s, const int fd, ssize_t *ret);
t_bool	str_cut_buf(t_str *dst, t_buf *src, const size_t i);
t_bool	buf_cut_str(t_buf *dst, t_str *src, const size_t i);

#endif //F_GNL_H
