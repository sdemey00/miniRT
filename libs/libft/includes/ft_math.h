/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:52:09 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/08 21:44:56 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# include "libft.h"
# include <math.h>

# define FT_PI 3.141592653589793

typedef float	t_rad;
typedef float	t_deg;

t_rad	deg_rad(t_deg d);
t_deg	rad_deg(t_rad r);

/* 3D vector with {x, y, z} components. */
typedef struct s_vec
{
	float	x;
	float	y;
	float	z;
}	t_vec;
// vec1.c
void	vec_print(const t_vec *v);
float	vec_mag(const t_vec v);
float	vec_dot(const t_vec a, const t_vec b);
t_vec	vec_norm(const t_vec a);
void	vec_inorm(t_vec *a);
// vec2.c
t_vec	vec_sum(const t_vec a, const t_vec b);
t_vec	vec_sub(const t_vec a, const t_vec b);
void	vec_isum(t_vec *dst, const t_vec src);
void	vec_isub(t_vec *dst, const t_vec src);
// vec3.c
t_vec	vec_scal(const t_vec v, const float scalar);
t_vec	vec_rscal(const t_vec v, const float scalar);
void	vec_iscal(t_vec *src, const float scalar);
void	vec_irscal(t_vec *src, const float scalar);
// vec4.c
t_vec	vec_cross(const t_vec a, const t_vec b);
void	vec_icross(t_vec *a, const t_vec b);
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
t_mat	mat_scal(const t_mat m, const float scalar);
void	mat_iscal(t_mat *m, const float scalar);
t_vec	mat_mul_vec(const t_mat m, const t_vec v);
void	mat_imul_vec(const t_mat m, t_vec *v);

float	ft_abs(float value);
t_bool	fts_abs(float *value);
t_luint	ft_fact(const t_uint n);
float	ft_pow(const float base, int exp);
int		ft_round(float value);
float	ft_pythagoras(const float a, const float b);
float	ft_sqrt(const float value);

#endif //FT_MATH_H
