/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_pixel_put_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 17:32:41 by talemari          #+#    #+#             */
/*   Updated: 2017/04/24 09:09:30 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"
#include "mlx.h"

void		mm_pixel_put_img(void *img, t_vec2i size, t_vec2i pos, t_color c)
{
	char	*imginfo;
	int		bpp;
	int		endian;
	int		sl;
	int		i;

	i = 0;
	(void)size;
	imginfo = mlx_get_data_addr(img, &bpp, &sl, &endian);
	while (i != bpp / 8)
	{
		imginfo[(pos.y * sl) + (pos.x * (bpp / 8)) + i++] = c.b;
		imginfo[(pos.y * sl) + (pos.x * (bpp / 8)) + i++] = c.g;
		imginfo[(pos.y * sl) + (pos.x * (bpp / 8)) + i++] = c.r;
		imginfo[(pos.y * sl) + (pos.x * (bpp / 8)) + i++] = c.t;
	}
	return ;
}
