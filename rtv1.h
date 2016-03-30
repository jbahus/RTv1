/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 12:27:43 by jbahus            #+#    #+#             */
/*   Updated: 2016/03/27 07:20:51 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <math.h>
# define H 1000
# define W 1500
# define OBJ_MAX 10
# define FOV 90

typedef struct		s_vec
{
	double			x;
	double			y;
	double			z;
}					t_vec;

typedef struct		s_color
{
	double			red;
	double			green;
	double			blue;
}					t_color;

typedef struct		s_light
{
	t_vec			o;
	t_color			i;
}					t_light;

typedef struct		s_sphere
{
	t_vec			position;
	double			radius;
	t_color			color;
}					t_sphere;

typedef struct		s_ray
{
	t_vec			o;
	t_vec			dir;
}					t_ray;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	int				bpp;
	int				sizeline;
	int				endian;
	char			*data;
}					t_mlx;

typedef struct		s_env
{
	t_mlx			mlx;
	int				num_obj;
	t_ray			camera;
	t_sphere		sphere;
	t_light			light;
	t_color			pix_color;
	double			d;
	double			t;
}					t_env;

void	ft_pixel_put_img(int i, int j, t_env *e);
void	draw_scene(t_env *e);

#endif