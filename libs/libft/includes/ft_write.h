/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:01:55 by mmichele          #+#    #+#             */
/*   Updated: 2025/08/04 21:41:49 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WRITE_H
# define FT_WRITE_H

# include "libft.h"

int		ft_printf(const char *s, ...);
int		ft_dprintf(int fd, const char *s, ...);

typedef enum e_aec_sty
{
	NORMAL = 0,
	BOLD = 1,
	FAINT = 2,
	ITALIC = 3,
	UNDERL = 4,
	BLINK = 5,
	INVERT = 7,
	HIDE = 8,
	STRIKE = 9,
}	t_aec_sty;

typedef enum e_aec_clr
{
	BLACK = 0,
	RED = 1,
	GREEN = 2,
	YELLOW = 3,
	BLUE = 4,
	MAGENTA = 5,
	CYAN = 6,
	WHITE = 7,
	DEFAULT = 9
}	t_aec_clr;

typedef struct s_aec
{
	t_aec_sty	sty;
	t_aec_clr	fg;
	t_aec_clr	bg;
}	t_aec;

t_bool	ft_aec_print(t_aec eac, const char *str, const t_bool newline);
char	*ft_aec_str(t_aec eac, const char *str, const t_bool newline);

#endif //FT_WRITE_H
