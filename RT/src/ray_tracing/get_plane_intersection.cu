/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plane_intersection.cu                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:25:30 by talemari          #+#    #+#             */
/*   Updated: 2017/06/03 17:23:16 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rt.cuh"

/*
** Checks for a ray-plane intersection.
*/

__device__
bool	get_plane_intersection(t_raytracing_tools *r, t_ray *ray, int index)
{
	t_intersection_tools	i;

	i.n_dir = 1;
	if (v_dot(r->scene->objects[index].dir, ray->dir) > 0)
		i.n_dir = -1;
	i.d1 = v_dot(v_scale(r->scene->objects[index].dir, i.n_dir), ray->dir);
	if (i.d1 > -1e-20)
		return (false);
	i.v1 = v_sub(r->scene->objects[index].pos, ray->origin);
	i.r1 = v_dot(i.v1, v_scale(r->scene->objects[index].dir, i.n_dir)) / i.d1;
	if (i.r1 < 0)
		return (false);
	r->t > i.r1 ? ray->t = i.r1 : 0.0;
	if (r->t > i.r1)
	{
		ray->hit_obj = index;
		ray->hit_type = T_PLANE;
	}
	return (true);
}

__device__
t_pt2	get_uv_plane(t_object *obj, t_ray *ray, t_vec3 *dim)
{
	t_pt2	coord;
	t_vec3	ortho_x;
	t_vec3	ortho_y;
	float	dot_norm;

	dot_norm = v_dot(v_new(0, 1, 0), ray->nhit);
	ortho_x = v_cross(ray->nhit, dot_norm < 0.001 && dot_norm > -0.001 ?
		v_new(0, 1, 0) : v_new(1, 0, 0));
	ortho_x = v_dot(ortho_x, v_new(0, 0, 1)) > 0 ?
		ortho_x : v_scale(ortho_x, -1);
	ortho_y = v_cross(ray->nhit, ortho_x);
	coord.x = (int)(v_dot(ortho_x, ray->hit) * obj->texture_ratio.x +
		obj->texture_translate.x) % (int)dim->x;
	coord.y = (int)(v_dot(ortho_y, ray->hit) * obj->texture_ratio.y +
		obj->texture_translate.y) % (int)dim->y;
	if (coord.x < 0)
		coord.x += -(coord.x / (int)dim->x) * (int)dim->x + (int)dim->x;
	if (coord.y < 0)
		coord.y += -(coord.y / (int)dim->y) * (int)dim->y + (int)dim->y;
	return (coord);
}
