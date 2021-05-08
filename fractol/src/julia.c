/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 17:08:37 by talemari          #+#    #+#             */
/*   Updated: 2017/02/13 12:18:36 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_color	mand_color(int i, int it_max)
{
	t_color		color;

	if (i <= (it_max / 4))
		color = (t_color){0, 0, 0, i * 5};
	if (i > (it_max / 4) && i <= (it_max / 3))
		color = (t_color){0, i * 5, 0, 255};
	if (i > (it_max / 3) && i <= (it_max / 2))
		color = (t_color){0, 255, i * 5, 255};
	if (i > (it_max / 2) && i <= it_max)
		color = (t_color){0, 255, 255, 255};
	return (color);
}

static t_color	mand_iter(t_fract mand)
{
	int		i;

	i = -1;
	while (++i < mand.it_max)
	{
		mand.tmp = mand.zr;
		mand.zr = mand.zr * mand.zr - mand.zi * mand.zi + mand.cr;
		mand.zi = 2 * mand.zi * mand.tmp + mand.ci;
		if (mand.zr * mand.zr + mand.zi * mand.zi >= 4)
			return (mand_color(i, mand.it_max));
	}
	return (mm_hex_to_color(BLACK));
}

void			julia(t_data *data)
{
	t_fract		jul;
	t_vec2i		pos;

	jul = *data->fract;
	pos.x = 0;
	while (++pos.x < WIDTH)
	{
		pos.y = 0;
		while (++pos.y < HEIGHT)
		{
			jul.zr = (long double)pos.x / jul.zoomv + jul.p1.x;
			jul.zi = (long double)pos.y / jul.zoomv + jul.p1.y;
			mm_pixel_put(data->target, pos, mand_iter(jul), TRUE);
		}
	}
}
