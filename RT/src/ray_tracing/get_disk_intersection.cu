/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_disk_intersection.cu                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:29:23 by talemari          #+#    #+#             */
/*   Updated: 2017/06/03 14:09:39 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rt.cuh"

/*
** Checks for a ray-disk intersection.
*/

__device__
bool	get_disk_intersection(t_raytracing_tools *r, t_ray *ray, int index)
{
	t_intersection_tools	i;
	t_vec3					hitpoint;

	i.n_dir = 1;
	if (v_dot(r->scene->objects[index].dir, ray->dir) > 0)
		i.n_dir = -1;
	i.d1 = v_dot(v_scale(r->scene->objects[index].dir, i.n_dir), ray->dir);
	if (i.d1 > -1e-6)
		return (false);
	i.v1 = v_sub(r->scene->objects[index].pos, ray->origin);
	i.r1 = v_dot(i.v1, v_scale(r->scene->objects[index].dir, i.n_dir)) / i.d1;
	if (i.r1 < 0)
		return (false);
	hitpoint = v_add(ray->origin, v_scale(ray->dir, i.r1));
	if (v_length(v_sub(hitpoint, r->scene->objects[index].pos)) >
		r->scene->objects[index].rad)
		return (false);
	r->t > i.r1 ? ray->t = i.r1 : 0;
	if (r->t > i.r1)
	{
		ray->hit_obj = index;
		ray->hit_type = T_DISK;
	}
	return (true);
}
