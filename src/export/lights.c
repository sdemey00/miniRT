/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:00:24 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/16 22:06:15 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "export.h"

static void	export_light(const int fd, t_light *l)
{
	(void)l;
	ft_dprintf(fd, "L %.2f,%.2f,%.2f %.2f %d,%d,%d\n", l->pos.x, l->pos.y, \
		l->pos.z, l->intensity, (t_ssuint)l->color.x, (t_ssuint)l->color.y, \
		(t_ssuint)l->color.z);
}

void	export_lights(const int fd, t_light l[], t_len len)
{
	t_idx	i;

	i = 0;
	while (i < len)
	{
		export_light(fd, &l[i]);
		i++;
	}
}
