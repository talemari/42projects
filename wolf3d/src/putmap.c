/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 11:51:41 by talemari          #+#    #+#             */
/*   Updated: 2017/01/17 11:52:22 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	putmap(t_map map)
{
	t_vec2i		pos;

	pos.y = 0;
	while (pos.y < map.size.y)
	{
		pos.x = 0;
		while (pos.x < map.size.x)
		{
			ft_putnbr(map.coord[pos.y][pos.x]);
			ft_putchar(' ');
			pos.x++;
		}
		ft_putchar('\n');
		pos.y++;
	}
}
