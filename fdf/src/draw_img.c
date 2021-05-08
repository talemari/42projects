/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 13:19:08 by talemari          #+#    #+#             */
/*   Updated: 2017/01/06 18:06:30 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mymlx.h"
#include "mlx.h"
#include <math.h>
#include <stdlib.h>

static t_vec2i		**final_coord(t_dot dots)
{
	t_vec2i		**res;
	t_vec2f		tmp;
	t_vec2i		pos;

	pos = vec2i(0, 0);
	res = (t_vec2i **)malloc(sizeof(t_vec2i *) * dots.size.y);
	while (pos.y < dots.size.y)
	{
		pos.x = 0;
		res[pos.y] = (t_vec2i *)malloc(sizeof(t_vec2i) * dots.size.x);
		while (pos.x < dots.size.x)
		{
			tmp = mm_3d_to_ortho(dots.coord[pos.y][pos.x]);
			res[pos.y][pos.x] = vec2i(round(tmp.x), round(tmp.y));
			pos.x++;
		}
		pos.y++;
	}
	return (res);
}

void				draw_img(t_data data)
{
	t_vec2i		pos;
	t_vec2i		**vert;
	t_dot		dots;
	t_color		color;

	pos = vec2i(0, 0);
	dots = data.dots;
	vert = final_coord(dots);
	color = mm_hex_to_color(BLUE);
	while (pos.y < dots.size.y)
	{
		pos.x = 0;
		while (pos.x < dots.size.x)
		{
			if (pos.x + 1 < dots.size.x)
				mm_line(data.target, vert[pos.y][pos.x], vert[pos.y][pos.x + 1],
						color);
			if (pos.y + 1 < dots.size.y)
				mm_line(data.target, vert[pos.y][pos.x], vert[pos.y + 1][pos.x],
						color);
			pos.x++;
		}
		pos.y++;
	}
}
