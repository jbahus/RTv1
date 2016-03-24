/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_put_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 10:25:55 by jbahus            #+#    #+#             */
/*   Updated: 2016/03/04 17:04:54 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_pixel_put_img(t_env *e)
{
	e->data[(int)e->ray.start.y * e->sizeline +
		(int)e->ray.start.x * (e->bpp / 8) + 0] = 255;
	e->data[(int)e->ray.start.y * e->sizeline +
		(int)e->ray.start.x * (e->bpp / 8) + 1] = 0;
	e->data[(int)e->ray.start.y * e->sizeline +
		(int)e->ray.start.x * (e->bpp / 8) + 2] = 0;
}
