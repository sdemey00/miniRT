/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 20:19:28 by mmichele          #+#    #+#             */
/*   Updated: 2025/08/04 22:44:40 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMORY_H
# define FT_MEMORY_H

# include "libft.h"

void	ft_bzero(void *s, unsigned int n);
void	*ft_calloc(unsigned int nmemb, unsigned int size);
t_bool	ft_free(void **p, ...);
t_bool	fts_malloc(void **dst, t_size size);
t_bool	ft_memadd(void **dst, const void *src, const t_size dst_size, \
	const t_size src_size);
void	*ft_memchr(const void *s, int c, unsigned int n);
t_bool	ft_memcpy(void *dest, const void *src, t_size n);
void	*ft_memdup(const void *src, const t_size unit, const t_len n);
t_idx	ft_memmax(void *mem, t_size unit, t_len len, \
	t_sign (*cmp)(const void *, const void *));
t_idx	ft_memmin(void *mem, t_size unit, t_len len, \
	t_sign (*cmp)(const void *, const void *));
t_bool	fts_memdup(void **dst, const void *src, const t_size unit, \
	const t_len n);
void	*ft_memmove(void *dest, const void *src, unsigned int n);
void	*ft_memset(void *s, int c, unsigned int n);
t_bool	ft_memswap(void *a, void *b, t_size unit);
t_bool	ft_nfree(void ***p, t_len n);
t_len	ft_parrlen(void **arr);
t_bool	fts_realloc(void **mem, const t_size old_size, const t_size new_size);

#endif //FT_MEMORY_H
