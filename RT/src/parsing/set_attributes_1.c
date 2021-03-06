/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_attributes_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 15:47:55 by talemari          #+#    #+#             */
/*   Updated: 2017/06/08 11:49:08 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rt.cuh"

/*
** Sets parsed attributes to current object based on current type.
*/

static void	set_attributes_by_obj_type(t_parse_tools *t, t_attributes *a);

void		set_attributes(t_parse_tools *t, t_attributes *a)
{
	t->current_type == T_CAMERA ? set_attributes_camera(t, a) : 0;
	t->current_type == T_LIGHT ? set_attributes_light(t, a) : 0;
	if (t->current_type == T_CAMERA || t->current_type == T_LIGHT)
		return ;
	if (!v_isnan(a->pos))
		t->current_object->pos = a->pos;
	if (!v_isnan(a->dir))
		t->current_object->dir = a->dir;
	if (!v_isnan(a->col))
		t->current_object->col = a->col;
	if (a->parent_index)
		t->current_object->parent_index = a->parent_index;
	!isnan(a->ior) ? t->current_object->ior = a->ior : 0;
	!isnan(a->beer_lambert) ? t->current_object->beer_lambert =
													a->beer_lambert : 0;
	!isnan(a->reflection) ? t->current_object->reflection = a->reflection : 0;
	if (!isnan(a->specular_exp))
		t->current_object->specular_exp = a->specular_exp;
	!isnan(a->ks) ? t->current_object->ks = a->ks : 0;
	!isnan(a->kd) ? t->current_object->kd = a->kd : 0;
	if (!isnan(a->transparency))
		t->current_object->transparency = a->transparency;
	if (t->current_type == T_PLANE || t->current_type == T_DISK)
		set_attributes_plane(t, a);
	set_attributes_by_obj_type(t, a);
}

static void	set_attributes_by_obj_type(t_parse_tools *t, t_attributes *a)
{
	t->current_type == T_SPHERE ? set_attributes_sphere(t, a) : 0;
	t->current_type == T_CYLINDER ? set_attributes_cylinder(t, a) : 0;
	t->current_type == T_CONE ? set_attributes_cone(t, a) : 0;
	t->current_type == T_PARABOLOID ? set_attributes_paraboloid(t, a) : 0;
}

void		set_attributes_camera(t_parse_tools *t, t_attributes *a)
{
	if (!v_isnan(a->pos))
		t->current_camera->pos = a->pos;
	if (!isnan(a->fov))
		t->current_camera->fov = a->fov;
	if (!v_isnan(a->dir))
		t->current_camera->dir = a->dir;
	if (!v_isnan(a->look_at))
		t->current_camera->look_at = a->look_at;
	if (a->filter != 0)
		t->current_camera->filter = a->filter;
	if (!isnan(a->ior))
		t->current_camera->ior = a->ior;
}

void		set_attributes_light(t_parse_tools *t, t_attributes *a)
{
	if (!v_isnan(a->pos))
		t->current_light->pos = a->pos;
	if (!v_isnan(a->dir))
		t->current_light->dir = a->dir;
	if (!v_isnan(a->look_at))
		t->current_light->look_at = a->look_at;
	if (!v_isnan(a->col))
		t->current_light->col = a->col;
	if (!isnan(a->intensity))
		t->current_light->intensity = a->intensity;
}
