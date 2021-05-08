/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trigger_scaling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 10:43:06 by talemari          #+#    #+#             */
/*   Updated: 2017/01/04 16:52:46 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include "mlx.h"

static t_mat4x4f	final_mat(t_vec3f scale, t_vec3f origin, t_vec3f bscale)
{
	t_mat4x4f	res;
	t_mat4x4f	newscale;
	t_mat4x4f	trans;

	trans = mm_mat_translation(origin);
	newscale = mm_mat_scale(vec3f(1 / (bscale.x / 1), 1 / (bscale.y / 1),
				1 / (bscale.z / 1)));
	res = mm_mat_mult4x4(trans, newscale);
	newscale = mm_mat_scale(scale);
	res = mm_mat_mult4x4(res, newscale);
	trans = mm_mat_translation(vec3f(-origin.x, -origin.y, -origin.z));
	res = mm_mat_mult4x4(res, trans);
	return (res);
}

static void			mm_scaling(t_data *data, t_vec3f scale, t_vec3f bscale)
{
	t_mat4x4f	mat;
	t_vec2i		pos;

	mat = final_mat(scale, data->dots.coord[data->dots.size.y / 2]
			[data->dots.size.x / 2], bscale);
	pos.y = 0;
	while (pos.y < data->dots.size.y)
	{
		pos.x = 0;
		while (pos.x < data->dots.size.x)
		{
			data->dots.coord[pos.y][pos.x] = mm_mat4x4_mult_vec3f(
					data->dots.coord[pos.y][pos.x], mat);
			pos.x++;
		}
		pos.y++;
	}
	pos.x = mlx_destroy_image(data->target.mlx, data->target.img);
	data->target.img = mlx_new_image(data->target.mlx, WIDTH, HEIGHT);
	draw_img(*data);
	mlx_put_image_to_window(data->target.mlx, data->target.win, data->target.img, 0, 0);
}

void				trigger_scaling(int keycode, t_data *data)
{
	static float	scalex = 1;
	static float	scaley = 1;
	static float	scalez = 1;
	t_vec3f			bscale;

	bscale = vec3f(scalex, scaley, scalez);
	if (keycode == 119 || keycode == 115)
		scalex += (keycode == 115) ? -DEFAULT_SCALING : DEFAULT_SCALING;
	if (keycode == 97 || keycode == 100)
		scaley += (keycode == 97) ? -DEFAULT_SCALING : DEFAULT_SCALING;
	mm_scaling(data, vec3f(scalex, scaley, scalez), bscale);
}
