/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 16:56:40 by talemari          #+#    #+#             */
/*   Updated: 2017/01/04 16:46:17 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "mymlx.h"

void		set_data(char **g, t_data *data)
{
	data->scale = vec2f(1, 1);
	data->target.mlx = mlx_init();
	store_dots(g, &data->base);
	mm_dotcpy(data->base, &data->dots);
	fdf_to_iso(data->base, &data->dots);
	data->target.win = mlx_new_window(data->target.mlx, WIDTH, HEIGHT, "fdf");
	data->target.img = mlx_new_image(data->target.mlx, WIDTH, HEIGHT);
	data->target.size = (t_vec2i){WIDTH, HEIGHT};
	data->target.size = vec2i(WIDTH, HEIGHT);
}
