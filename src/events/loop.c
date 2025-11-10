/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:01:53 by sdemey            #+#    #+#             */
/*   Updated: 2025/11/10 14:43:45 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	loop_handler(struct s_ctx *c)
{
	if (!c->rendered && time_now() - c->t >= 2)
	{
		window_draw(&c->w, &c->s, raytracing);
		c->t = 0;
		c->rendered = 1;
	}
	return (0);
}
