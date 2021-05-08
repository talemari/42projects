/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 12:10:09 by talemari          #+#    #+#             */
/*   Updated: 2017/02/13 13:00:31 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mymlx.h"

# define WIDTH 800
# define HEIGHT 800
# define MOAR_ZOOM 1.15
# define LESS_ZOOM 0.85

typedef struct		s_vec2d
{
	double			x;
	double			y;
}					t_vec2d;

typedef struct		s_fract
{
	t_vec2d			p1;
	t_vec2d			p2;
	double			zr;
	double			zi;
	double			cr;
	double			ci;
	double			tmp;
	double			zoomv;
	t_vec2f			zoom;
	int				it_max;
	int				type;
}					t_fract;

typedef struct		s_data
{
	t_target		target;
	t_fract			*fract;
	int				type;
}					t_data;

int					key_is_pressed(int keycode, void *param);
int					mouse_is_pressed(int keycode, int x, int y, void *param);
int					mouse_motion(int x, int y, t_data *data);
t_bool				set_data(t_data *data, char *av);
void				tricorn(t_data *data);
void				julia(t_data *data);
void				mandelbrot(t_data *data);
void				trigger_zoom(int keycode, t_data *data, t_vec2i mousepos);

#endif
