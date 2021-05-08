/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_mat_rotation_x.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 12:11:52 by talemari          #+#    #+#             */
/*   Updated: 2016/12/29 11:59:47 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"
#include "math.h"

t_mat4x4f		mm_mat_rotation_x(float a)
{
	t_mat4x4f	res;

	res.v[0][0] = 1;
	res.v[0][1] = 0;
	res.v[0][2] = 0;
	res.v[0][3] = 0;
	res.v[1][0] = 0;
	res.v[1][1] = cos(a);
	res.v[1][2] = -(sin(a));
	res.v[1][3] = 0;
	res.v[2][0] = 0;
	res.v[2][1] = sin(a);
	res.v[2][2] = cos(a);
	res.v[2][3] = 0;
	res.v[3][0] = 0;
	res.v[3][1] = 0;
	res.v[3][2] = 0;
	res.v[3][3] = 1;
	return (res);
}
