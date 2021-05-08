/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 16:58:49 by talemari          #+#    #+#             */
/*   Updated: 2017/04/21 10:13:40 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		draw_line(int x, t_color color, t_vec2i line, t_target target)
{
	while (line.x < line.y)
	{
		mm_pixel_put(target, (t_vec2i){x, line.x}, color, TRUE);
		line.x++;
	}
}

static t_color	get_color(t_map map, t_vec2i mpos)
{
	t_color res;

	if (map.coord[mpos.x][mpos.y] == 1)
		res = mm_hex_to_color(BLUE);
	else if (map.coord[mpos.x][mpos.y] == 2)
		res = mm_hex_to_color(TEAL);
	else if (map.coord[mpos.x][mpos.y] == 3)
		res = mm_hex_to_color(RED);
	else if (map.coord[mpos.x][mpos.y] == 4)
		res = mm_hex_to_color(WHITE);
	else
		res = mm_hex_to_color(YELLOW);
	return (res);
}

static void		color_side(t_color *wall)
{
	wall->g /= 2;
	wall->r /= 2;
	wall->b /= 2;
}

void			draw_img(t_data *data)
{
	int		x;
	t_vec2i	line;
	int		lineh;
	t_color	wall;

	x = -1;
	while (x++ < WIDTH)
	{
		set_ray(data, x);
		lineh = (int)(HEIGHT / data->ray.wdis);
		line.x = -lineh / 2 + HEIGHT / 2;
		if (line.x < 0)
			line.x = 0;
		line.y = lineh / 2 + HEIGHT / 2;
		if (line.y >= HEIGHT)
			line.y = HEIGHT - 1;
		wall = get_color(data->map, data->ray.mpos);
		if (data->ray.side == 1)
			color_side(&wall);
		draw_line(x, wall, line, data->target);
	}
}
