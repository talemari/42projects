/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_to_iso.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 13:50:22 by talemari          #+#    #+#             */
/*   Updated: 2017/01/06 18:06:49 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mymlx.h"
#include <math.h>
#include <stdlib.h>

void		fdf_to_iso(const t_dot base, t_dot *dots)
{
	t_vec2i		pos;

	pos.y = 0;
	dots->coord = (t_vec3f **)malloc(sizeof(t_vec3f *) * base.size.y);
	while (pos.y < base.size.y)
	{
		pos.x = 0;
		dots->coord[pos.y] = (t_vec3f *)malloc(sizeof(t_vec3f) * base.size.x);
		while (pos.x < base.size.x)
		{
			dots->coord[pos.y][pos.x] = base.coord[pos.y][pos.x];
			pos.x++;
		}
		pos.y++;
	}
	dots->size = base.size;
}
