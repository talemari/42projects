/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_putdot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 11:46:32 by talemari          #+#    #+#             */
/*   Updated: 2017/01/17 11:50:27 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

void	mm_putdot(t_dot dots)
{
	t_vec2i		pos;

	pos.y = 0;
	while (pos.y < dots.size.y)
	{
		pos.x = 0;
		while (pos.x < dots.size.x)
		{
			ft_putnbr(dots.coord[pos.y][pos.x].z);
			ft_putchar(' ');
			pos.x++;
		}
		ft_putchar('\n');
		pos.y++;
	}
}
