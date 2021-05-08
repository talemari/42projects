/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cone_intersection.cu                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:30:04 by talemari          #+#    #+#             */
/*   Updated: 2017/06/08 11:21:27 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rt.cuh"

__device__
void	get_finite_cone_intersection(t_ray *ray,
	t_object *object, t_intersection_tools *i);
__device__
bool	lower_than_min(float r, t_intersection_tools *i, t_object *obj,
	t_ray *ray);
__device__
bool	higher_than_max(float r, t_intersection_tools *i, t_object *obj,
	t_ray *ray);

/*
** Checks for a ray-cone intersection.
*/

__device__
bool		get_cone_intersection(t_raytracing_tools *r, t_ray *ray,
			int index)
{
	t_intersection_tools i;

	i.d1 = tan(r->scene->objects[index].angle);
	i.v1 = v_sub(ray->origin, r->scene->objects[index].pos);
	i.q.x = v_dot(ray->dir, ray->dir) - (1.0 + i.d1 * i.d1) *
		powf(v_dot(ray->dir, r->scene->objects[index].dir), 2.0);
	i.q.y = 2 * (v_dot(ray->dir, i.v1) - (1.0 + i.d1 * i.d1) * v_dot(ray->dir,
		r->scene->objects[index].dir) *
		v_dot(i.v1, r->scene->objects[index].dir));
	i.q.z = v_dot(i.v1, i.v1) - (1.0 + i.d1 * i.d1) * powf(v_dot(i.v1,
		r->scene->objects[index].dir), 2.0);
	if (!solve_quadratic(i.q, &i.r1, &i.r2) || (i.r1 < 0 && i.r2 < 0))
		return (false);
	if (i.r2 < i.r1)
		ft_swapf(&i.r1, &i.r2);
	get_finite_cone_intersection(ray, &r->scene->objects[index], &i);
	(i.r1 < 0 || isnan(i.r1)) ? i.r1 = i.r2 : 0;
	if (i.r1 < 0 || isnan(i.r1))
		return (false);
	r->t > i.r1 ? ray->t = i.r1 : 0;
	(r->t > i.r1) ? ray->hit_obj = index : 0;
	(r->t > i.r1) ? ray->hit_type = T_CONE : 0;
	return (true);
}

__device__
void	get_finite_cone_intersection(t_ray *ray,
	t_object *obj, t_intersection_tools *i)
{
	bool	r1_too_low;
	bool	r1_too_high;
	bool	r2_too_low;
	bool	r2_too_high;

	r1_too_low = lower_than_min(i->r1, i, obj, ray) || i->r1 == -1;
	r1_too_high = higher_than_max(i->r1, i, obj, ray) || i->r1 == -1;
	r2_too_low = lower_than_min(i->r2, i, obj, ray) || i->r2 == -1;
	r2_too_high = higher_than_max(i->r2, i, obj, ray) || i->r2 == -1;
	if (r1_too_low || r1_too_high)
	{
		i->r1 = NAN;
		if (r2_too_low || r2_too_high)
			i->r2 = NAN;
	}
	else if (!r1_too_low && !r1_too_high)
		i->r2 = NAN;
}

__device__
bool	lower_than_min(float r, t_intersection_tools *i, t_object *obj,
	t_ray *ray)
{
	if (r > 0)
	{
		if (v_dot(obj->dir, v_sub(v_add(ray->origin,
			v_scale(ray->dir, r)), obj->pos)) < 0.0)
			return (true);
	}
	else
		return (true);
	return (false);
}

__device__
bool	higher_than_max(float r, t_intersection_tools *i, t_object *obj,
	t_ray *ray)
{
	if (r > 0)
	{
		if (v_dot(obj->dir, v_sub(v_add(ray->origin, v_scale(ray->dir, r)),
			v_add(obj->pos, v_scale(obj->dir, obj->height)))) > 0.0)
			return (true);
	}
	else
		return (true);
	return (false);
}

__device__
t_pt2		get_uv_cone(t_object *obj, t_ray *ray, t_vec3 *dim)
{
	t_pt2	coord;
	t_vec3	hit_center;

	hit_center = v_scale(ray->nhit, -1);
	coord.x = (0.5 + (atan2f(hit_center.z, hit_center.x) /
		(float)(2 * M_PI))) * dim->x;
	coord.y = (v_dist(obj->pos, ray->hit) /
		sqrtf(obj->height * obj->height + obj->rad * obj->rad)) * dim->y;
	coord.x %= (int)dim->x;
	coord.y %= (int)dim->y;
	return (coord);
}
