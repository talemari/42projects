/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_3d_to_ortho.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 13:27:33 by talemari          #+#    #+#             */
/*   Updated: 2016/12/22 13:31:21 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

t_vec2f		mm_3d_to_ortho(t_vec3f vec)
{
	t_mat3x3f	ortho;
	t_vec3f		temp;
	t_vec2f		res;

	ortho = mm_mat_ortho_projection();
	temp = mm_vec_multi_mat(vec, ortho);
	res.x = temp.x;
	res.y = temp.y;
	return (res);
}
