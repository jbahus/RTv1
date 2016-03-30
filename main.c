/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 18:29:23 by jbahus            #+#    #+#             */
/*   Updated: 2016/03/26 23:25:54 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		expose_hook(t_env *e)
{
	draw_scene(e);
	mlx_clear_window(e->mlx.mlx, e->mlx.win);
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->mlx.img, 0, 0);
	return (0);
}

int		key_hook(int key_code, t_env *e)
{
	if (key_code == 53)
	{
		mlx_destroy_image(e->mlx.mlx, e->mlx.img);
		mlx_destroy_window(e->mlx.mlx, e->mlx.win);
		free(e->mlx.mlx);
		exit(0);
	}
	ft_bzero(e->mlx.data, (sizeof(char) * W * H * (e->mlx.bpp / 8)));
	expose_hook(e);
	return (0);
}

int		main(void)
{
	t_env		e;

	if (!(e.mlx.mlx = mlx_init()))
	{
		ft_putendl_fd("Error.", 2);
		return (0);
	}
	e.mlx.win = mlx_new_window(e.mlx.mlx, W, H, "RTv1");
	e.mlx.img = mlx_new_image(e.mlx.mlx, W, H);
	e.mlx.data = mlx_get_data_addr(e.mlx.img, &e.mlx.bpp,
		&e.mlx.sizeline, &e.mlx.endian);
	mlx_key_hook(e.mlx.win, &key_hook, &e);
	mlx_expose_hook(e.mlx.win, &expose_hook, &e);
	mlx_loop(e.mlx.mlx);
	return (0);
}