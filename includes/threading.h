/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 14:59:21 by mmichele          #+#    #+#             */
/*   Updated: 2026/04/16 18:23:13 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREADING_H
# define THREADING_H

# include "structs.h"

# include <pthread.h>

typedef struct s_thread_ctx
{
	t_window		*w;
	t_scene			s;
	unsigned int	id;
	pthread_mutex_t	*mtx;
}	t_thread_ctx;

#endif // THREADING_H