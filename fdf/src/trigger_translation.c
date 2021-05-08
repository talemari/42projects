/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trigger_translation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 11:53:16 by talemari          #+#    #+#             */
/*   Updated: 2017/01/06 18:07:42 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include "mlx.h"

static void		translation_x(int keycode, t_data *data)
{
	t_mat4x4f	mat;
	t_vec2i		pos;
	t_vec3f		dot;

	mat = mm_mat_translation(vec3f((keycode == 65361) ? -DEFAULT_TRANSLATION :
				DEFAULT_TRANSLATION, 1, 1));
	pos.y = 0;
	while (pos.y < data->dots.size.y)
	{
		pos.x = 0;
		while (pos.x < data->dots.size.x)
		{
			dot = data->dots.coord[pos.y][pos.x];
			data->dots.coord[pos.y][pos.x] = mm_mat4x4_mult_vec3f(dot, mat);
			pos.x++;
		}
		pos.y++;
	}
	pos.x = mlx_destroy_image(data->target.mlx, data->target.img);
	data->target.img = mlx_new_image(data->target.mlx, WIDTH, HEIGHT);
	draw_img(*data);
	mlx_put_image_to_window(data->target.mlx, data->target.win, data->target.img, 0, 0);
}

static void		translation_y(int keycode, t_data *data)
{
	t_mat4x4f	mat;
	t_vec2i		pos;
	t_vec3f		dot;

	mat = mm_mat_translation(vec3f(0, (keycode == 65362) ? -DEFAULT_TRANSLATION :
				DEFAULT_TRANSLATION, 0));
	pos.y = 0;
	while (pos.y < data->dots.size.y)
	{
		pos.x = 0;
		while (pos.x < data->dots.size.x)
		{
			dot = data->dots.coord[pos.y][pos.x];
			data->dots.coord[pos.y][pos.x] = mm_mat4x4_mult_vec3f(dot, mat);
			pos.x++;
		}
		pos.y++;
	}
	pos.x = mlx_destroy_image(data->target.mlx, data->target.img);
	data->target.img = mlx_new_image(data->target.mlx, WIDTH, HEIGHT);
	draw_img(*data);
	mlx_put_image_to_window(data->target.mlx, data->target.win, data->target.img, 0, 0);
}

void			trigger_translation(int keycode, void *data)
{
	if (keycode == 65361 || keycode == 65363)
		translation_x(keycode, data);
	if (keycode == 65362 || keycode == 65364)
		translation_y(keycode, data);
}
