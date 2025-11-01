/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:02:14 by mmichele          #+#    #+#             */
/*   Updated: 2025/10/29 15:15:52 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# ifndef VERBOSE
#  define VERBOSE 0
# endif

# ifdef WIDTH
#  if WIDTH < 100 || 1920 < WIDTH
#   undef WIDTH
#  endif
# endif
# ifndef WIDTH
#  define WIDTH 1600
# endif

# ifdef HEIGHT
#  if HEIGHT < 100 || 1080 < HEIGHT
#   undef HEIGHT
#  endif
# endif
# ifndef HEIGHT
#  define HEIGHT 900
# endif

# include "libft.h"
# include "mlx.h"
# include "structs.h"
# include "parsing.h"
# include <math.h>
# include <stdio.h>
# include <fcntl.h>

/* MLX controller event codes */
# define WIN_CLOSE 17
# define KEY_ESC 65307

/* Graphical library context */
typedef struct s_gctx
{
	void	*mlx;
	void	*win;
	void	*img;
}	t_gctx;

/* Execution context */
typedef struct s_ectx
{
	t_gctx	g;
}	t_ectx;

// winctx.c
t_bool	gctx_init(t_gctx *g);
t_bool	gctx_free(t_gctx *g);
int		ectx_close(void *ectx);

#endif // MINIRT_H
