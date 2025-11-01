/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:52:09 by mmichele          #+#    #+#             */
/*   Updated: 2025/07/12 01:17:27 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# include "libft.h"
# include <math.h>

# define FT_PI 3.141593

typedef float	t_rad;

/* 3D vector with {x, y, z} components. */
typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
}	t_vec;
// vec1.c
void	vec_print(const t_vec *v);
double	vec_mag(const t_vec *v);
double	vec_dot(const t_vec *a, const t_vec *b);
// vec2.c
t_vec	vec_sum(const t_vec a, const t_vec b);
t_vec	vec_sub(const t_vec a, const t_vec b);
void	vec_isum(t_vec *dst, const t_vec src);
void	vec_isub(t_vec *dst, const t_vec src);
// vec3.c
t_vec	vec_scal(const t_vec v, const double scalar);
t_vec	vec_rscal(const t_vec v, const double scalar);
void	vec_iscal(t_vec *src, const double scalar);
void	vec_irscal(t_vec *src, const double scalar);
// rotx.c
t_vec	vec_rotx(const t_vec v, const t_rad a);
void	vec_irotx(t_vec *v, const t_rad a);
// roty.c
t_vec	vec_roty(const t_vec v, const t_rad a);
void	vec_iroty(t_vec *v, const t_rad a);
// rotz.c
t_vec	vec_rotz(const t_vec v, const t_rad a);
void	vec_irotz(t_vec *v, const t_rad a);

/* 3D matrix each line containing {x, y, z} components. */
typedef struct s_mat
{
	t_vec	v[3];
}	t_mat;
// mat1.c
void	mat_print(const t_mat *m);
t_mat	mat_scal(const t_mat m, const double scalar);
void	mat_iscal(t_mat *m, const double scalar);
t_vec	mat_mul_vec(const t_mat m, const t_vec v);
void	mat_imul_vec(const t_mat m, t_vec *v);

double	ft_abs(double value);
t_bool	fts_abs(double *value);
t_luint	ft_fact(const t_uint n);
t_luint	ft_pow(const t_uint base, t_uint exp);
int		ft_round(float value);
float	ft_pythagoras(const float a, const float b);
double	ft_sqrt(const double value);

#endif //FT_MATH_H
