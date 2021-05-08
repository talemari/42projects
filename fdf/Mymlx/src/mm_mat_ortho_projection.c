/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_mat_ortho_projection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 13:22:11 by talemari          #+#    #+#             */
/*   Updated: 2016/12/22 13:24:52 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

t_mat3x3f		mm_mat_ortho_projection(void)
{
	t_mat3x3f	res;

	res.v[0][0] = 1;
	res.v[0][1] = 0;
	res.v[0][2] = 0;
	res.v[1][0] = 0;
	res.v[1][1] = 1;
	res.v[1][2] = 0;
	res.v[2][0] = 0;
	res.v[2][1] = 0;
	res.v[2][2] = 0;
	return (res);
}
