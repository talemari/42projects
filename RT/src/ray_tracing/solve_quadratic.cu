/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_quadratic.cu                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 13:25:29 by talemari          #+#    #+#             */
/*   Updated: 2017/04/26 11:15:46 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rt.cuh"

/*
** Solves a quadratic equation.
** Updates r1 and r2 if at least a solution exists.
** Returns true if the quadratic has at least one solution.
*/

__device__
bool	solve_quadratic(t_vec3 q, float *r1, float *r2)
{
	float	d;

	*r1 = -1;
	*r2 = -1;
	d = q.y * q.y - 4 * q.x * q.z;
	if (d == 0)
	{
		*r1 = -q.y / (2 * q.x);
		return (true);
	}
	if (d > 0)
	{
		*r1 = (-q.y + sqrtf(d)) / (2 * q.x);
		*r2 = (-q.y - sqrtf(d)) / (2 * q.x);
		return (true);
	}
	return (false);
}
