/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_put_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 10:25:55 by jbahus            #+#    #+#             */
/*   Updated: 2016/03/30 01:54:06 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		get_min(double a, double b)
{
	if (a < b)
		return ((int)a);
	else
		return ((int)b);
}

void	ft_pixel_put_img(int i, int j, t_env *e)
{
	e->mlx.data[j * e->mlx.sizeline + i * (e->mlx.bpp / 8) + 0] = (int)e->pix_color.red;
	e->mlx.data[j * e->mlx.sizeline + i * (e->mlx.bpp / 8) + 1] = (int)e->pix_color.green;
	e->mlx.data[j * e->mlx.sizeline + i * (e->mlx.bpp / 8) + 2] = (int)e->pix_color.blue;
}
