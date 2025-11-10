/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 23:27:53 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/02 12:55:30 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPES_H
# define FT_TYPES_H

# include "libft.h"

# define FT_DBL_MAX 1.7976931348623157e+308

/* Representing a boolean. Range : [0, 1] */
typedef unsigned char		t_bool;
/* Represents a sign [-1, 0, 1] or a magnitude of difference. */
typedef signed char			t_sign;
/* Unsigned integer used to index on arrays. */
typedef unsigned int		t_idx;
/* Signed integer used to index on arrays, allows to go from top to bottom. */
typedef long int			t_ridx;
/* Represents a byte of memory. */
typedef unsigned char		t_byte;
/* Represents a number of bytes. */
typedef unsigned int		t_size;
/* Represents an abstract length. */
typedef unsigned int		t_len;

/* Aliases */
typedef unsigned char		t_ssuint;	// 8  bit unsigned int
typedef short unsigned int	t_suint;	// 16 bit unsigned int
typedef unsigned int		t_uint;		// 32 bit unsigned int
typedef long unsigned int	t_luint;	// 64 bit unsigned int

typedef signed char			t_ssint;	// 8  bit int
typedef short int			t_sint;		// 16 bit int
typedef long int			t_lint;		// 64 bit int

typedef long double			t_quad;		// quadruple precision float
#endif // FT_TYPES_H
