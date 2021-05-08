/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_mat_mult4x4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 13:50:16 by talemari          #+#    #+#             */
/*   Updated: 2016/12/26 13:53:55 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

t_mat4x4f		mm_mat_mult4x4(t_mat4x4f mat1, t_mat4x4f mat2)
{
	t_mat4x4f	res;
	int			x;
	int			y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			res.v[y][x] = (mat1.v[y][0] * mat2.v[0][x]) + (mat1.v[y][1] *
					mat2.v[1][x]) + (mat1.v[y][2] * mat2.v[2][x]) +
						(mat1.v[y][3] * mat2.v[3][x]);
			x++;
		}
		y++;
	}
	return (res);
}
