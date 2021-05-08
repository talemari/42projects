/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trigger_zoom.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:14:44 by talemari          #+#    #+#             */
/*   Updated: 2017/02/14 12:08:00 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

static void		jul_zoom(t_fract *jul, float zoom)
{
	jul->zoomv *= zoom;
	jul->it_max *= zoom;
}

static void		mand_zoom(t_fract *mand, float zoom, t_vec2i mousepos)
{
	t_vec2f		pos;

	pos.x = ((float)mousepos.x / WIDTH) *
		(mand->p2.x - mand->p1.x) + mand->p1.x;
	pos.y = ((float)mousepos.y / HEIGHT) *
		(mand->p2.y - mand->p1.y) + mand->p1.y;
	mand->p1 = (t_vec2d){pos.x + (pos.x * zoom), pos.y + (pos.y * zoom)};
	mand->p2 = (t_vec2d){pos.x - (pos.x * zoom), pos.y - (pos.y * zoom)};
	mand->zoomv *= zoom;
	mand->it_max *= zoom;
}

void			trigger_zoom(int keycode, t_data *data, t_vec2i mousepos)
{
	float		zoomv;

	zoomv = (keycode == 1 || keycode == 5) ? MOAR_ZOOM : LESS_ZOOM;
	mlx_destroy_image(data->target.mlx, data->target.img);
	data->target.img = mlx_new_image(data->target.mlx, WIDTH, HEIGHT);
	if (data->fract->type == 1)
	{
		mand_zoom(data->fract, zoomv, mousepos);
		mandelbrot(data);
	}
	else if (data->fract->type == 2)
	{
		jul_zoom(data->fract, zoomv);
		julia(data);
	}
	else if (data->fract->type == 3)
	{
		mand_zoom(data->fract, zoomv, mousepos);
		tricorn(data);
	}
	mlx_put_image_to_window(data->target.mlx, data->target.win,
			data->target.img, 0, 0);
}
