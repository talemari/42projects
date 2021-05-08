/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_dotcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 11:05:33 by talemari          #+#    #+#             */
/*   Updated: 2017/01/06 17:58:18 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"
#include <stdlib.h>

void		mm_dotcpy(const t_dot src, t_dot *dst)
{
	t_vec2i		pos;

	dst->size = vec2i(src.size.x, src.size.y);
	pos.y = 0;
	dst->coord = (t_vec3f **)malloc(sizeof(t_vec3f *) * dst->size.y);
	while (pos.y < dst->size.y)
	{
		pos.x = 0;
		dst->coord[pos.y] = (t_vec3f *)malloc(sizeof(t_vec3f) * dst->size.x);
		while (pos.x < dst->size.x)
		{
			dst->coord[pos.y][pos.x] = src.coord[pos.y][pos.x];
			pos.x++;
		}
		pos.y++;
	}
}
