/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 08:50:17 by mmichele          #+#    #+#             */
/*   Updated: 2025/11/06 18:42:36 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_bindings(void)
{
	ft_printf("OVERALL\n");
	ft_printf("%-18s : Quit\n", "<ESC>");
	ft_printf("%-18s : Full render\n", "<p>");
	ft_printf("%-18s : Export\n", "<e>");
	ft_printf("%-18s : Movements\n", "<w,a,s,d,SPACE,c>");
	ft_printf("CAMERA MODE\n");
	ft_printf("%-18s : Orientation\n", "<i,j,k,l>");
	ft_printf("%-18s : FOV\n", "<-,=>");
	ft_printf("%-18s : Take or release, control of object\n", "<e,MOUSE>");
	ft_printf("%-18s : Toggle reticle\n", "<x>");
	ft_printf("OBJECT MODE\n");
	ft_printf("%-18s : Orientation\n", "<i,j,k,l,u,o>");
	ft_printf("%-18s : Radius\n", "<t,g>");
	ft_printf("%-18s : Height\n", "<y,h>");
}

int	main(int argc, char **argv)
{
	struct s_ctx	c;

	c.rendering = 0;
	if (argc != 2)
		return (!!dprintf(2, "Error\nUsage: %s <scene.rt>\n", argv[0]));
	if (!scene_init(&c.s, argv[1]) || !window_init(&c.w))
		return (1);
	print_bindings();
	window_draw(&c.w, &c.s);
	mlx_hook(c.w.win, WIN_CLOSE, 0, window_close, &c.w);
	mlx_hook(c.w.win, 3, 2, key_release, &c);
	mlx_hook(c.w.win, 4, 1L << 2, mouse_press, &c);
	mlx_loop_hook(c.w.mlx, controller_loop, &c);
	mlx_loop(c.w.mlx);
	return (0);
}
