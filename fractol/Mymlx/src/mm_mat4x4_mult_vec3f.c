/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_mat4x4_mult_vec3f.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 13:05:14 by talemari          #+#    #+#             */
/*   Updated: 2017/01/06 17:58:57 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"
#include <math.h>

t_vec3f		mm_mat4x4_mult_vec3f(t_vec3f v, t_mat4x4f m)
{
	t_vec3f		res;
	int			w;

	w = 1;
	res.x = v.x * m.v[0][0] + v.y * m.v[0][1] + v.z * m.v[0][2] + m.v[0][3];
	res.y = v.x * m.v[1][0] + v.y * m.v[1][1] + v.z * m.v[1][2] + m.v[1][3];
	res.z = v.x * m.v[2][0] + v.y * m.v[2][1] + v.z * m.v[2][2] + m.v[2][3];
	w = v.x * m.v[3][0] + v.y * m.v[3][1] + v.z * m.v[3][2] + m.v[3][3];
	if (w != 1)
	{
		res.x = res.x / w;
		res.y = res.y / w;
		res.z = res.z / w;
	}
	return (res);
}
