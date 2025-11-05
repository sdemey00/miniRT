/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 23:31:39 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/02 15:07:06 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	mat_print(const t_mat *m)
{
	t_ssuint	i;

	i = 0;
	while (i < 3)
	{
		ft_printf("%.2f, %.2f, %.2f\n", m->v[i].x, m->v[i].y, m->v[i].z);
		i++;
	}
}

t_mat	mat_scal(const t_mat m, const float scalar)
{
	t_mat	res;

	res = m;
	mat_iscal(&res, scalar);
	return (res);
}

void	mat_iscal(t_mat *m, const float scalar)
{
	vec_iscal(&m->v[0], scalar);
	vec_iscal(&m->v[1], scalar);
	vec_iscal(&m->v[2], scalar);
}

t_vec	mat_mul_vec(const t_mat m, const t_vec v)
{
	return ((t_vec){vec_dot(&m.v[0], &v), \
					vec_dot(&m.v[1], &v), \
					vec_dot(&m.v[2], &v)});
}

void	mat_imul_vec(const t_mat m, t_vec *v)
{
	*v = mat_mul_vec(m, *v);
}
