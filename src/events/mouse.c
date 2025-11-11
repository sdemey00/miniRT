/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:01:57 by sdemey            #+#    #+#             */
/*   Updated: 2025/11/11 17:14:59 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* Hooks mouse clicking events. */
int	mouse_press(int key, int x, int y, struct s_ctx *c)
{
	(void)c;
	if (VERBOSE)
		ft_printf("Mouse pressed with key %d at %d %d\n", key, x, y);
	return (0);
}
