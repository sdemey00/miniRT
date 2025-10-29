/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_printf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:34:40 by mmichele          #+#    #+#             */
/*   Updated: 2025/05/31 15:17:23 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_PRINTF_H
# define F_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <unistd.h>

typedef struct s_flags
{
	t_bool	map[6];
	t_uint	padding;
	t_uint	precision;
	char	format;
	int		fd;
}	t_flags;

enum e_flag
{
	E_SPACE,
	E_PLUS,
	E_SHARP,
	E_MINUS,
	E_ZERO,
	E_DOT
};

typedef struct s_idxstr
{
	size_t		i;
	const char	*s;
}	t_idxstr;

size_t			t_flags_init(t_flags *flags, t_idxstr *is, int fd);

unsigned int	f_pad(int fd, int size, const unsigned char iszero);
unsigned int	f_putnbr(int nbr, const t_flags *flags);
unsigned int	f_putchar(const char chr, const t_flags *flags);
int				f_putstr(const char *str, const t_flags *flags);
unsigned int	f_puthex(unsigned int hex, const t_flags *flags);
unsigned int	f_putptr(long unsigned int ptr, const t_flags *flags);
unsigned int	f_putuint(unsigned int nbr, const t_flags *flags);
int				f_vdprintf(int fd, const char *s, va_list ap);

#endif // F_PRINTF_H