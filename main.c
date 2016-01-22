/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 18:29:23 by jbahus            #+#    #+#             */
/*   Updated: 2016/01/22 12:53:01 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		expose_hook(t_env *e)
{
	ft_test(e);
	mlx_clear_window(e->mlx, e->win);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

int		key_hook(int key_code, t_env *e)
{
	if (key_code == 53)
		exit(0);
	ft_bzero(e->data, (sizeof(char) * L * H * (e->bpp / 8)));
	expose_hook(e);
	return (0);
}

int		main(void)
{
	t_env	e;

	if (!(e.mlx = mlx_init()))
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	e.win = mlx_new_window(e.mlx, L, H, "RTv1");
	e.img = mlx_new_image(e.mlx, L, H);
	e.data = mlx_get_data_addr(e.img, &e.bpp, &e.sizeline, &e.endian);
	mlx_key_hook(e.win, &key_hook, &e);
	mlx_expose_hook(e.win, &expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}