/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 16:59:15 by jbahus            #+#    #+#             */
/*   Updated: 2016/03/04 17:18:27 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_init(t_env *e)
{
	e->spheres.pos.x = 200;
	e->spheres.pos.y = 200;
	e->spheres.pos.z = 200;
	e->spheres.radius = 100;
	e->ray.dir.z = 1;
	e->ray.start.z = 0;
	e->material.diffuse.red = 1;
	e->material.diffuse.green = 0;
	e->material.diffuse.blue = 0;
	e->material.reflection = 0.5;
	e->light.pos.x = 0;
	e->light.pos.y = 240;
	e->light.pos.z = 0;
	e->light.intensity.red = 1;
	e->light.intensity.green = 1;
	e->light.intensity.blue = 1;
}