/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 12:27:43 by jbahus            #+#    #+#             */
/*   Updated: 2016/01/29 16:02:02 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <math.h>
# define H 1000
# define L 1500
# define FOV 30

typedef struct		s_vec
{
	float			x;
	float			y;
	float			z;
}					t_vec;

typedef struct
{
	float			red;
	float			green;
	float			blue;
}					colour;

typedef struct
{
	colour			intensity;
	t_vec			pos;
}					material;

typedef struct
{
	t_vec			pos;
	colour			intensity;
}					light;

typedef struct		s_ray
{
	t_vec			start;
	t_vec			dir;
}					t_ray;

typedef struct		s_sphere
{
	t_vec			pos;
	float			radius;
	int				material;
}					t_sphere;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	int				bpp;
	int				sizeline;
	int				endian;
	char			*data;
	int				color;
	int				x;
	int				y;
	//t_sphere		s;
	t_ray			ray;
	colour			colour;
	light			light;
	t_sphere		spheres;
}					t_env;

//int		ft_test(t_env *e);
void	ft_pixel_put_img(t_env *e, int i, int j);

#endif