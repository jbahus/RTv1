/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 12:39:45 by jbahus            #+#    #+#             */
/*   Updated: 2016/01/29 14:28:26 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_next(t_env *e)
{
	int		x;
	int		y;
	int		r;
	int		d;

	r = 0;
	y = 0;
	while (y <= 200)
	{
		x = 0;
		d = r - 1;
		while (x <= r)
		{

			ft_pixel_put_img(e, x + 750, r + 500);
			ft_pixel_put_img(e, r + 750, x + 500);
			ft_pixel_put_img(e, -x + 750, r + 500);
			ft_pixel_put_img(e, -r + 750, x + 500);
			ft_pixel_put_img(e, x + 750, -r + 500);
			ft_pixel_put_img(e, r + 750, -x + 500);
			ft_pixel_put_img(e, -x + 750, -r + 500);
			ft_pixel_put_img(e, -r + 750, -x + 500);
			if (d >= 2 * x)
			{
				d = d - 2 * x - 1;
				x++;
			}
			else if (d < 2 * (y - r))
			{
				d = d + 2 * r -1;
				r--;
			}
			else
			{
				d = d + 2 * (r - x - 1);
				r--;
				x++;
			}
		}
		y++;
		r = y;
	}
}

float	vector_dot(t_vec v1, t_vec v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vec	vector_sub(t_vec v1, t_vec v2)
{
	t_vec	result;

	result.x = v1.x * v2.x;
	result.y = v1.y * v2.y;
	result.z = v1.z * v2.z;
	return (result);
}

int		ft_test(t_env *e, float *t)
{
	float	a;
	float	b;
	float	c;
	float	discr;
	t_vec	dist;
	float	sqrtdiscr;
	float	t0;
	float	t1;
	int		ret;

	ret = 0;
	a = vector_dot(e->ray.dir, e->ray.dir);
	dist = vector_sub(e->ray.start, e->spheres.pos);
	b = 2 * vector_dot(e->ray.dir, dist);
	c = vector_dot(dist, dist) - (e->spheres.radius * e->spheres.radius);
	discr = b * b - 4 * a * c;
	if (discr < 0)
		ret = 0;
	else
	{
		ret = 1;
		/*sqrtdiscr = sqrtf(discr);
		t0 = (-b + sqrtdiscr) / 2;
		t1 = (-b - sqrtdiscr) / 2;
		if (t0 > t1)
			t0 = t1;
		if ((t0 > 0.001f) && (t0 < *t))
		{
			*t = t0;
			ret = 1;
		}
		else
			ret = 0;*/
	}
	return (ret);
}