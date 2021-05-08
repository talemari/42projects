/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_mat_translation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 14:03:44 by talemari          #+#    #+#             */
/*   Updated: 2016/12/28 13:57:03 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"
#include "math.h"

t_mat4x4f		mm_mat_translation(t_vec3f vec)
{
	t_mat4x4f	res;

	res.v[0][0] = 1;
	res.v[0][1] = 0;
	res.v[0][2] = 0;
	res.v[0][3] = vec.x;
	res.v[1][0] = 0;
	res.v[1][1] = 1;
	res.v[1][2] = 0;
	res.v[1][3] = vec.y;
	res.v[2][0] = 0;
	res.v[2][1] = 0;
	res.v[2][2] = 1;
	res.v[2][3] = vec.z;
	res.v[3][0] = 0;
	res.v[3][1] = 0;
	res.v[3][2] = 0;
	res.v[3][3] = 1;
	return (res);
}
