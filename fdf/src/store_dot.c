/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_dot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 11:57:39 by talemari          #+#    #+#             */
/*   Updated: 2017/01/11 10:07:42 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

static t_vec2i	set_size(char **g)
{
	t_vec2i		pos;
	t_vec2i		size;
	int			trash;

	size = vec2i(0, 0);
	pos = vec2i(0, 0);
	while (get_next_nbr(g[0], &trash))
		size.x++;
	while (g[pos.y])
	{
		size.y++;
		pos.y++;
	}
	return (size);
}

void			store_dots(char **g, t_dot *base)
{
	t_vec2i	pos;
	t_vec2i	newpos;
	int		temp;

	pos = vec2i(0, 0);
	newpos = vec2i(0, 0);
	base->size = set_size(g);
	base->seg_size = WIDTH / (base->size.x);
	base->coord = (t_vec3f **)malloc(sizeof(t_vec3f *) * base->size.y);
	while (g[pos.y])
	{
		base->coord[pos.y] = (t_vec3f *)malloc(sizeof(t_vec3f) * base->size.x);
		pos.x = 0;
		newpos.x = 0;
		while (get_next_nbr(g[pos.y], &temp))
		{
			base->coord[newpos.y][newpos.x] = vec3f(newpos.x * base->seg_size,
													newpos.y * base->seg_size,
													temp * base->seg_size);
			newpos.x++;
		}
		newpos.y++;
		pos.y++;
	}
}
