/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 15:27:47 by talemari          #+#    #+#             */
/*   Updated: 2017/01/07 14:42:09 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"
#include "mlx.h"

void	mm_pixel_put(t_target target, t_vec2i pos, t_color color, t_bool img)
{
	if (img == FALSE)
		mlx_pixel_put(target.mlx, target.win,
				pos.x, pos.y, mm_color_to_hex(color));
	else
		mm_pixel_put_img(target.img, target.size, pos, color);
}
