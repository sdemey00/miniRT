/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:00:16 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/21 22:09:21 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "export.h"

void	export_bump_textures(const int fd, t_obj *o)
{
	if (o->bump.e_type == PROC_WAVE)
		ft_dprintf(fd, "b=1");
	//else if (o->bump.e_type == PROC_NOISE)
	//	ft_dprintf(fd, "");
	else if (o->bump.e_type == XPM_TEX)
		ft_dprintf(fd, "b=tex");
	else if (o->bump.e_type == XPM_BUMP)
		ft_dprintf(fd, "b=%s", o->bump.texture);
}

//void	export_visual_textures(const int fd, t_obj *o)
//{
//	if (o->texture.loaded)
//		ft_dprintf("x=%s", o->texture.path);
//}

void	export_other_args(const int fd, t_obj *o)
{
	ft_dprintf(fd, " s=%d r=%.1f c=%u\n", (t_ssuint)o->shininess, \
		o->reflexion, bitmap_get(&o->effects, CHECKER_PATTERN));
}

void	export_object(const int fd, t_obj *o)
{
	if (o->e_type == SPH)
		ft_dprintf(fd, "sp %.2f,%.2f,%.2f %.2f %d,%d,%d", o->pos.x, \
			o->pos.y, o->pos.z, o->radius * 2.0, (t_ssuint)o->color.x, \
			(t_ssuint)o->color.y, (t_ssuint)o->color.z);
	else if (o->e_type == PLA)
		ft_dprintf(fd, "pl %.2f,%.2f,%.2f %f,%f,%f %d,%d,%d", \
			o->pos.x, o->pos.y, o->pos.z, o->dir.x, o->dir.y, o->dir.z, \
			(t_ssuint)o->color.x, (t_ssuint)o->color.y, (t_ssuint)o->color.z);
	else if (o->e_type == CYL)
		ft_dprintf(fd, "cy %.2f,%.2f,%.2f %f,%f,%f %.2f %.2f %d,%d,%d", \
			o->pos.x, o->pos.y, o->pos.z, o->dir.x, o->dir.y, o->dir.z, \
			o->radius * 2.0, o->height, (t_ssuint)o->color.x, \
			(t_ssuint)o->color.y, (t_ssuint)o->color.z);
	else if (o->e_type == CIR)
		ft_dprintf(fd, "ci %.2f,%.2f,%.2f %f,%f,%f %.2f %d,%d,%d", \
			o->pos.x, o->pos.y, o->pos.z, o->dir.x, o->dir.y, o->dir.z, \
			o->radius * 2.0, (t_ssuint)o->color.x, (t_ssuint)o->color.y, \
			(t_ssuint)o->color.z);
	else if (o->e_type == CON)
		ft_dprintf(fd, "co %.2f,%.2f,%.2f %f,%f,%f %d,%d,%d", \
			o->pos.x, o->pos.y, o->pos.z, o->dir.x, o->dir.y, o->dir.z, \
			(t_ssuint)o->color.x, (t_ssuint)o->color.y, (t_ssuint)o->color.z);
	export_bump_textures(fd, o);
	//export_visual_textures(fd, o);
	export_other_args(fd, o);
}

void	export_objects(const int fd, t_obj o[], t_len len)
{
	t_idx	i;

	i = 0;
	while (i < len)
	{
		export_object(fd, &o[i]);
		i++;
	}
}
