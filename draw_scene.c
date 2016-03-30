/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 21:58:07 by jbahus            #+#    #+#             */
/*   Updated: 2016/03/30 08:42:54 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

double	vector_dot(t_vec *a, t_vec *b)
{
	return ((a->x * b->x) + (a->y * b->y) + (a->z * b->z));
}

t_vec	vector_sub(t_vec *a, t_vec *b)
{
	t_vec	ret;

	ret.x = b->x - a->x;
	ret.y = b->y - a->y;
	ret.z = b->z - a->z;
	return (ret);
}

t_vec	vector_normalize(t_vec *vec)
{
	t_vec	ret;
	double	length;

	length = sqrt(vector_dot(vec, vec));
	ret.x = vec->x / length;
	ret.y = vec->y / length;
	ret.z = vec->z / length;
	return (ret);
}

t_vec	vector_cross(t_vec *a, t_vec *b)
{
	t_vec	ret;

	ret.x = (a->y * b->z) - (b->y * a->z);
	ret.y = (a->z * b->x) - (b->z * a->x);
	ret.z = (a->x * b->y) - (b->x * a->y);
	return (ret);
}

/*t_vec	vector_add(t_vec *a, t_vec *b)
{
	t_vec	ret;

	ret.x = a->x + b->x;
	ret.y = a->y + b->y;
	ret.z =	a->z + b->z;
	return (ret);
}*/

t_vec	vector_scale(double c, t_vec *vec)
{
	t_vec	ret;

	ret.x = vec->x * c;
	ret.y = vec->y * c;
	ret.z = vec->z * c;
	return (ret);
}

int		intersect_sphere(t_sphere *sphere, t_ray *ray, double *t)
{
	double	a;
	double	b;
	double	c;
	double	discr;
	double	t0;
	double	t1;
	t_vec	dist;

	a = vector_dot(&ray->dir, &ray->dir);
	dist = vector_sub(&sphere->position, &ray->o);
	b = 2 * vector_dot(&ray->dir, &dist);
	c = vector_dot(&dist, &dist) - (sphere->radius * sphere->radius);
	discr = b * b - 4 * a * c;
	if (discr < 0)
		return (0);
	else
	{
		discr = sqrt(discr);
		t0 = (-b + discr) / (2 * a);
		t1 = (-b - discr) / (2 * a);
		if (t0 > t1)
			t0 = t1;
		if (t0 > 0.001 && t0 < *t)
		{
			*t = t0;
			return (1);
		}
		else
			return (0);
	}
}

void	draw_scene(t_env *e)
{
	int		j;
	int		i;
	// t_vec	new_start;
	//t_vec	scale;
	t_vec	n;
	t_vec 	inter;
	t_vec	light_ray;
	// double	dist;
	double	il;
	// double	lambert;

	j = 0;
	e->sphere.position.x = 750;
	e->sphere.position.y = 500;
	e->sphere.position.z = 200;
	e->sphere.radius = 100;
	e->camera.dir.x = 0;
	e->camera.dir.y = 0;
	e->camera.dir.z = 1;
	e->camera.o.z = -100;
	e->light.i.red = 255;
	e->light.i.green = 255;
	e->light.i.blue = 255;
	e->light.o.x = 0;
	e->light.o.y = 0;
	e->light.o.z = -100;
	e->sphere.color.red = 255;
	e->sphere.color.green = 0;
	e->sphere.color.blue = 0;
	while (j < H)
	{
		i = 0;
		while (i < W)
		{
			e->pix_color.red = 0;
			e->pix_color.green = 0;
			e->pix_color.blue = 0;
			e->camera.o.y = j;
			e->camera.o.x = i;
			// coef = 1.0;
			// while (coef > 0.0f)
			// {
				e->t = 5000;
				if (intersect_sphere(&e->sphere, &e->camera, &e->t))
				{
					// printf("%f\n", e->t);
					inter = vector_scale(e->t, &e->camera.o);
					light_ray = vector_sub(&inter, &e->light.o);
					n = vector_sub(&inter, &e->sphere.position);
					n = vector_normalize(&n);
					light_ray = vector_normalize(&light_ray);
					il = vector_dot(&light_ray, &n);
					if (il <= 0.0)
						il = 1;
					il = acos(il) * 40.7436609389;
					il *= 7;
					// printf("%f\n", (il * 180 / M_PI));
					// il = ((il * 180) / (2 * M_PI));
					e->pix_color.red = il * (e->sphere.color.red + e->light.i.red);
					e->pix_color.green = il * (e->sphere.color.green + e->light.i.green);
					e->pix_color.blue = il * (e->sphere.color.blue + e->light.i.blue);
					printf("%f\n", e->pix_color.red);
					printf("%f\n", e->pix_color.green);
					printf("%f\n", e->pix_color.blue);
				}
				// coef *= 0.2;
				// e->camera.o = new_start;
				// reflect = 2.0f * vector_dot(&e->camera.dir, &n);
				// temp = vector_scale(reflect, &n);
				// e->camera.dir = vector_sub(&e->camera.dir, &temp);
			// }
			ft_pixel_put_img(i, j, e);
			i++;
		}
		j++;
	}
}