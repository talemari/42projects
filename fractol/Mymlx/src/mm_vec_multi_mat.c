/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_vec_multi_mat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 12:29:25 by talemari          #+#    #+#             */
/*   Updated: 2016/12/23 12:09:23 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"
#include <math.h>

t_vec3f		mm_vec_multi_mat(t_vec3f vec, t_mat3x3f m)
{
	t_vec3f		res;

	res.x = (vec.x * m.v[0][0]) + (vec.y * m.v[0][1]) + (vec.z * m.v[0][2]);
	res.y = (vec.x * m.v[1][0]) + (vec.y * m.v[1][1]) + (vec.z * m.v[1][2]);
	res.z = (vec.x * m.v[2][0]) + (vec.y * m.v[2][1]) + (vec.z * m.v[2][2]);
	return (res);
}
