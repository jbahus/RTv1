/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 18:29:23 by jbahus            #+#    #+#             */
/*   Updated: 2016/03/04 17:44:42 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec vector_scale(float c, t_vec v)
{
	t_vec	result;

	result.x = v.x * c;
	result.y = v.y * c;
	result.z = v.z * c;
	return (result);
}

t_vec vector_add(t_vec v1, t_vec v2)
{
	t_vec	result;

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;
	return (result);
}

float	vector_dot(t_vec v1, t_vec v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vec	vector_sub(t_vec v1, t_vec v2)
{
	t_vec	result;

	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;
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
		sqrtdiscr = sqrtf(discr);
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
			ret = 0;
	}
	return (ret);
}

void	ft_do_it(t_env *e)
{
	int		hit;
	colour	col;
	float	coef;
	float	t;
	int		lvl;
	int		current_s;

	col.red = 0;
	col.green = 0;
	col blue = 0;
	e->ray.start.y = 0;
	while (e->ray.start.y < L)
	{
		e->ray.start.x = 0;
		while (e->ray.start.x < H)
		{
			t = 20000.0f;
			current_s = 0;
			
			hit = ft_test(e);
			if (hit)
				ft_pixel_put_img(e);
			e->ray.start.x++;
		}
		e->ray.start.y++;
	}
}

int		expose_hook(t_env *e)
{
	ft_init(e);
	ft_do_it(e);
	mlx_clear_window(e->mlx, e->win);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

int		key_hook(int key_code, t_env *e)
{
	if (key_code == 53)
	{
		mlx_destroy_image(e->mlx, e->img);
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	ft_bzero(e->data, (sizeof(char) * L * H * (e->bpp / 8)));
	expose_hook(e);
	return (0);
}

int		main(void)
{
	t_env		e;

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