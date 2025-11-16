/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:50:06 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/16 23:11:35 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPORT_H
# define EXPORT_H

# include "minirt.h"

void	export_ambiant(const int fd, const t_ambiant *a);
void	export_camera(const int fd, t_camera *c);
void	export_lights(const int fd, t_light l[], t_len len);
void	export_objects(const int fd, t_obj o[], t_len len);

#endif // EXPORT_H