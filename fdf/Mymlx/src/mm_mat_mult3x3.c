/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_mat_mult3x3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 15:40:58 by talemari          #+#    #+#             */
/*   Updated: 2016/12/23 12:22:32 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

t_mat3x3f		mm_mat_mult3x3(t_mat3x3f mat1, t_mat3x3f mat2)
{
	t_mat3x3f	res;
	int			x;
	int			y;

	y = 0;
	while (y < 3)
	{
		x = 0;
		while (x < 3)
		{
			res.v[y][x] = (mat1.v[y][0] * mat2.v[0][x]) + (mat1.v[y][1] *
					mat2.v[1][x]) + (mat1.v[y][2] * mat2.v[2][x]);
			x++;
		}
		y++;
	}
	return (res);
}
