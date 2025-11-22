/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 11:45:03 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/22 11:58:39 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPILE_H
# define COMPILE_H

# ifndef VERBOSE
#  define VERBOSE 0
# endif

# ifdef WIDTH
#  if WIDTH < 100 || 3800 < WIDTH
#   undef WIDTH
#  endif
# endif
# ifndef WIDTH
#  define WIDTH 1600
# endif

# ifdef HEIGHT
#  if HEIGHT < 100 || 2000 < HEIGHT
#   undef HEIGHT
#  endif
# endif
# ifndef HEIGHT
#  define HEIGHT 900
# endif

# ifdef MAX_OBJS
#  if MAX_OBJS < 1 || 512 < MAX_OBJS
#   undef MAX_OBJS
#  endif
# endif
# ifndef MAX_OBJS
#  define MAX_OBJS 16
# endif

# ifndef START_RENDER
#  define START_RENDER 1
# endif

#endif // COMPILE_H
