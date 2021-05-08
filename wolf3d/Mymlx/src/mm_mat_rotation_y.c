/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_mat_rotation_y.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 12:11:52 by talemari          #+#    #+#             */
/*   Updated: 2016/12/26 14:02:45 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"
#include "math.h"

t_mat4x4f		mm_mat_rotation_y(float a)
{
	t_mat4x4f	res;

	res.v[0][0] = cos(a);
	res.v[0][1] = 0;
	res.v[0][2] = sin(a);
	res.v[0][3] = 0;
	res.v[1][0] = 0;
	res.v[1][1] = 1;
	res.v[1][2] = 0;
	res.v[1][3] = 0;
	res.v[2][0] = -(sin(a));
	res.v[2][1] = 0;
	res.v[2][2] = cos(a);
	res.v[2][3] = 0;
	res.v[3][0] = 0;
	res.v[3][1] = 0;
	res.v[3][2] = 0;
	res.v[3][3] = 1;
	return (res);
}
