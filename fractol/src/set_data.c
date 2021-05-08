/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 12:21:18 by talemari          #+#    #+#             */
/*   Updated: 2017/02/13 12:51:17 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <stdlib.h>

static void		tricorn_init(t_fract *t)
{
	t->p1 = (t_vec2d){-2.1, -1.2};
	t->p2 = (t_vec2d){0.6, 1.2};
	t->zr = 0;
	t->zi = 0;
	t->cr = 0;
	t->ci = 0;
	t->tmp = 0;
	t->zoomv = 300;
	t->it_max = 50;
	t->type = 3;
}

static void		julia_init(t_fract *j)
{
	j->p1 = (t_vec2d){-1, -1.2};
	j->p2 = (t_vec2d){1, 1.2};
	j->zoomv = 300;
	j->it_max = 50;
	j->zr = 0;
	j->zi = 0;
	j->cr = 0.285;
	j->ci = 0.01;
	j->tmp = 0;
	j->type = 2;
}

static void		mand_init(t_fract *mand)
{
	mand->p1.x = -2.1;
	mand->p2.x = 0.6;
	mand->p1.y = -1.2;
	mand->p2.y = 1.2;
	mand->zr = 0;
	mand->zi = 0;
	mand->cr = 0;
	mand->ci = 0;
	mand->tmp = 0;
	mand->zoomv = 300;
	mand->it_max = 50;
	mand->type = 1;
}

static int		check_fract(t_data *data, char *av)
{
	if (ft_strcmp(av, "mandelbrot") == 0)
		mand_init(data->fract);
	else if (ft_strcmp(av, "julia") == 0)
		julia_init(data->fract);
	else if (ft_strcmp(av, "tricorn") == 0)
		tricorn_init(data->fract);
	else
	{
		ft_putendl("Error : Fractal type mismatch, Supported fractals are :");
		ft_putendl("mandelbrot, julia, tricorn");
		return (FALSE);
	}
	return (TRUE);
}

t_bool			set_data(t_data *data, char *av)
{
	data->target.mlx = mlx_init();
	data->target.win = mlx_new_window(data->target.mlx,
			WIDTH, HEIGHT, "Fractol");
	data->target.img = mlx_new_image(data->target.mlx, WIDTH, HEIGHT);
	if ((data->fract = (t_fract *)malloc(sizeof(t_fract))) == NULL)
		return (FALSE);
	if ((check_fract(data, av)) == FALSE)
		return (FALSE);
	if (data->fract->type == 1)
		mandelbrot(data);
	else if (data->fract->type == 2)
		julia(data);
	else if (data->fract->type == 3)
		tricorn(data);
	return (TRUE);
}
