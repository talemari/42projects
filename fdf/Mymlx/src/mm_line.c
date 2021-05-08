/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 17:37:37 by talemari          #+#    #+#             */
/*   Updated: 2017/01/07 14:28:12 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"
#include <math.h>

void	mm_line(t_target target, t_vec2i dep, t_vec2i end, t_color color)
{
	float	dx;
	float	dy;
	float	x;
	float	y;
	float	temp;

	x = dep.x;
	y = dep.y;
	dx = end.x - dep.x;
	dy = end.y - dep.y;
	temp = sqrt((dx * dx) + (dy * dy));
	dx /= temp;
	dy /= temp;
	while (temp >= 0)
	{
		mm_pixel_put(target, vec2i(x, y), color, TRUE);
		x += dx;
		y += dy;
		temp--;
	}
}
