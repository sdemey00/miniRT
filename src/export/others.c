/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:51:15 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/21 20:32:46 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "export.h"

void	export_ambiant(const int fd, const t_ambiant *a)
{
	ft_dprintf(fd, "A %.2f %d,%d,%d\n", a->intensity, \
		(t_ssuint)a->color.x, (t_ssuint)a->color.y, (t_ssuint)a->color.z);
}

void	export_camera(const int fd, t_camera *c)
{
	vec_inorm(&c->dir);
	ft_dprintf(fd, "C %.3f,%.3f,%.3f %f,%f,%f %u\n", c->pos.x, c->pos.y, \
		c->pos.z, c->dir.x, c->dir.y, c->dir.z, c->fov);
}
