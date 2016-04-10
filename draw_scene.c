/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 21:58:07 by jbahus            #+#    #+#             */
/*   Updated: 2016/04/10 06:17:42 by jbahus           ###   ########.fr       */
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

t_vec	vector_add(t_vec *a, t_vec *b)
{
	t_vec	ret;

	ret.x = a->x + b->x;
	ret.y = a->y + b->y;
	ret.z =	a->z + b->z;
	return (ret);
}

t_vec	vector_scale(double c, t_vec *vec)
{
	t_vec	ret;

	ret.x = vec->x * c;
	ret.y = vec->y * c;
	ret.z = vec->z * c;
	return (ret);
}

int		intersect_plane(t_obj *plane, t_ray *ray, double *t)
{
	double	t0;
	t_vec	tmp;
	t_vec	n;
	double	denom;

	n = vector_normalize(&plane->o);
	denom = vector_dot(&n, &ray->o);
	if (denom > 0.01)
	{
		tmp = vector_sub(&ray->dir, &plane->o);
		t0 = vector_dot(&tmp, &n) / denom;
		if (t0 < *t)
		{
			*t = t0;
			return (1);
		}
	}
	return (0);
}

int		intersect_sphere(t_obj *obj, t_ray *ray, double *t)
{
	double	a;
	double	b;
	double	c;
	double	discr;
	double	t0;
	double	t1;
	t_vec	dist;

	a = vector_dot(&ray->dir, &ray->dir);
	dist = vector_sub(&obj->o, &ray->o);
	b = 2 * vector_dot(&ray->dir, &dist);
	c = vector_dot(&dist, &dist) - (obj->r * obj->r);
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
	int		x;
	// t_vec	new_start;
	//t_vec	scale;
	t_vec	n;
	t_vec 	inter;
	t_vec	light_ray;
	int		current_obj;
	double	t0;
	double	il;
	// double	lambert;

	j = 0;
	e->obj[0].o.x = 750;
	e->obj[0].o.y = 500;
	e->obj[0].o.z = 0;
	e->obj[0].r = 100;
	e->obj[0].color.red = 1.0;
	e->obj[0].color.green = 0.1;
	e->obj[0].color.blue = 0.1;
	e->obj[1].o.x = 200;
	e->obj[1].o.y = 300;
	e->obj[1].o.z = 100;
	e->obj[1].r = 50;
	e->obj[1].color.red = 0.1;
	e->obj[1].color.green = 1.0;
	e->obj[1].color.blue = 0.1;
	e->camera.dir.x = 0;
	e->camera.dir.y = 0;
	e->camera.dir.z = 1;
	e->camera.o.z = -100;
	e->light.i.red = 1;
	e->light.i.green = 1;
	e->light.i.blue = 1;
	e->light.o.x = 0;
	e->light.o.y = 0;
	e->light.o.z = 0;
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
			e->t = 5000;
			t0 = 5000;
			x = 0;
			current_obj = -1;
			//if (intersect_sphere(&e->obj, &e->camera, &e->t))
			//{
			while (x < 2)
			{
				if (intersect_sphere(&e->obj[x], &e->camera, &t0))
				{
					if (t0 < e->t)
					{
						e->t = t0;
						current_obj = x;
					}
				}
				x++;
			}
			if (current_obj != -1)
			{
				inter = vector_scale(e->t, &e->camera.dir);
				inter = vector_add(&inter, &e->camera.o);
				light_ray = vector_sub(&inter, &e->light.o);
				n = vector_sub(&inter, &e->obj[current_obj].o);
				n = vector_normalize(&n);
				light_ray = vector_normalize(&light_ray);
				il = vector_dot(&light_ray, &n);
			//	if (il <= 0.0)
					//il = 1;
				il = acos(il) * 0.3; //* 40.7436609389;
				// il *= 3.5;
				// printf("%f\n", (il * 180 / M_PI));
				// il = ((il * 180) / (2 * M_PI));
				printf("%f\n", il);
				e->pix_color.red = il * (e->obj[current_obj].color.red * e->light.i.red) * 255;
				e->pix_color.green = il * (e->obj[current_obj].color.green * e->light.i.green) * 255;
				e->pix_color.blue = il * (e->obj[current_obj].color.blue * e->light.i.blue) * 255;
				// printf("%f\n", e->pix_color.red);
				// printf("%f\n", e->pix_color.green);
				// printf("%f\n", e->pix_color.blue);
			}
			//}
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