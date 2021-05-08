/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_attributes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 15:41:22 by talemari          #+#    #+#             */
/*   Updated: 2017/06/07 20:25:42 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rt.cuh"

/*
** Resets the attributes.
*/

int	reset_attributes(t_attributes *att)
{
	att->res.x = -1;
	att->res.y = -1;
	att->ray_depth = -1;
	att->ka = NAN;
	att->ambient_light_color = v_new(NAN, NAN, NAN);
	att->intensity = NAN;
	att->fov = NAN;
	att->pos = v_new(NAN, NAN, NAN);
	att->dir = v_new(NAN, NAN, NAN);
	att->look_at = v_new(NAN, NAN, NAN);
	att->col = v_new(NAN, NAN, NAN);
	att->rad = NAN;
	att->height = NAN;
	att->ior = NAN;
	att->reflection = NAN;
	att->specular_exp = NAN;
	att->kd = NAN;
	att->ks = NAN;
	att->transparency = NAN;
	att->parent_index = 0;
	att->obj = NULL;
	return (1);
}
