/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_blackhole.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 00:00:00 by mmichele          #+#    #+#             */
/*   Updated: 2026/04/16 00:53:04 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
bh <center> <disk_normal> <horizon_diameter> <disk_diameter> <disk_color>
*/
t_bool	parse_blackhole(char **split, t_scene *scene, void *mlx)
{
	const t_ssuint	min_args = 5;
	const t_ssuint	max_args = min_args + OPTION_ARGS;
	t_obj			bh;

	if (!check_args_range(split, min_args, max_args))
	{
		print_error("Blackhole: invalid number of arguments\n");
		return (0);
	}
	obj_init(&bh);
	if (!parse_vec(split[0], &bh.pos)
		|| !parse_dir(split[1], &bh.dir)
		|| !parse_float(split[2], &bh.radius)
		|| !parse_float(split[3], &bh.height)
		|| !parse_color(split[4], &bh.color)
		|| !parse_optional_args(&split[min_args], &bh, mlx))
		return (0);
	if (bh.radius <= 0.0f)
		return (print_error("Blackhole: invalid horizon diameter\n"), 0);
	if (bh.height < 0.0f)
		return (print_error("Blackhole: invalid disk diameter\n"), 0);
	if (bh.height != 0.0f && bh.height <= bh.radius)
		return (print_error("Blackhole: invalid diameters\n"), 0);
	bh.radius /= 2.0f;
	bh.height /= 2.0f;
	bh.e_type = BH;
	if (!scene_add_obj(scene, &bh, mlx))
		return (0);
	return (1);
}

void	blackhole_print(const t_obj *blackhole)
{
	ft_printf("Blackhole center: %.2f, %.2f, %.2f\n",
		blackhole->pos.x, blackhole->pos.y,
		blackhole->pos.z);
	ft_printf("Disk normal: %.2f, %.2f, %.2f\n",
		blackhole->dir.x, blackhole->dir.y,
		blackhole->dir.z);
	ft_printf("Horizon radius: %.2f\n", blackhole->radius);
	ft_printf("Disk radius: %.2f\n", blackhole->height);
	ft_printf("Disk color: %d, %d, %d\n", (t_ssuint)blackhole->color.x,
		(t_ssuint)blackhole->color.y, (t_ssuint)blackhole->color.z);
}
