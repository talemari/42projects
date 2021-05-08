/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_motion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 11:40:30 by talemari          #+#    #+#             */
/*   Updated: 2017/02/13 12:43:25 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

int		mouse_motion(int x, int y, t_data *data)
{
	t_vec2f	pos;

	if (data->fract->type == 2 && (x > 0 && x < WIDTH) && (y > 0 && y < HEIGHT))
	{
		pos.x = (float)x / WIDTH * 2 - 1;
		pos.y = (float)y / HEIGHT * 2.4 - 1.2;
		mlx_destroy_image(data->target.mlx, data->target.img);
		data->target.img = mlx_new_image(data->target.mlx, WIDTH, HEIGHT);
		data->fract->cr = pos.x;
		data->fract->ci = pos.y;
		julia(data);
		mlx_put_image_to_window(data->target.mlx, data->target.win,
				data->target.img, 0, 0);
	}
	return (0);
}
