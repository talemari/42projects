/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trigger_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 13:56:26 by talemari          #+#    #+#             */
/*   Updated: 2017/01/03 14:36:40 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include "mlx.h"

static t_mat4x4f	final_mat(float a, int x, t_vec3f origin)
{
	t_mat4x4f	res;
	t_mat4x4f	trans;
	t_mat4x4f	rot;

	trans = mm_mat_translation(vec3f(origin.x, origin.y, origin.z));
	rot = (x == 1) ? mm_mat_rotation_x(a) : mm_mat_rotation_y(a);
	res = mm_mat_mult4x4(trans, rot);
	trans = mm_mat_translation(vec3f(-origin.x, -origin.y, -origin.z));
	res = mm_mat_mult4x4(res, trans);
	return (res);
}

static void			rotation_x(t_data *data, int keycode)
{
	t_mat4x4f	mat;
	t_vec2i		pos;
	t_vec3f		dot;

	pos.y = 0;
	while (pos.y < data->dots.size.y)
	{
		pos.x = 0;
		while (pos.x < data->dots.size.x)
		{
			dot = data->dots.coord[pos.y][pos.x];
			mat = final_mat((keycode == 65431) ? DEFAULT_ROTATION :
					-DEFAULT_ROTATION, 1, data->dots.coord
					[data->dots.size.y / 2][data->dots.size.x / 2]);
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

static void			rotation_y(t_data *data, int keycode)
{
	t_mat4x4f	mat;
	t_vec2i		pos;
	t_vec3f		dot;

	pos.y = 0;
	while (pos.y < data->dots.size.y)
	{
		pos.x = 0;
		while (pos.x < data->dots.size.x)
		{
			dot = data->dots.coord[pos.y][pos.x];
			mat = final_mat((keycode == 65433) ? DEFAULT_ROTATION :
					-DEFAULT_ROTATION, 0, data->dots.coord
					[data->dots.size.y / 2][data->dots.size.x / 2]);
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

void				trigger_rotation(int keycode, void *data)
{
	if (keycode == 65431 || keycode == 65433)
		rotation_x(data, keycode);
	if (keycode == 65430 || keycode == 65432)
		rotation_y(data, keycode);
}
