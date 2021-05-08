/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 12:23:23 by talemari          #+#    #+#             */
/*   Updated: 2017/01/17 14:58:43 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "mlx.h"
#include <stdio.h>

void	redraw(t_data *data)
{
	mlx_destroy_image(data->target.mlx, data->target.img);
	data->target.img = mlx_new_image(data->target.mlx, WIDTH, HEIGHT);
	draw_img(data);
	mlx_put_image_to_window(data->target.mlx, data->target.win,
			data->target.img, 0, 0);
}
