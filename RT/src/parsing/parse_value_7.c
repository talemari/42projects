/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_value_7.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:25:45 by talemari          #+#    #+#             */
/*   Updated: 2017/06/08 11:50:52 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rt.cuh"

/*
** Contains functions for parsing each value based on token.
*/

char	*parse_fov(t_parse_tools *t)
{
	float	new_fov;

	new_fov = NAN;
	if (isnan(new_fov = parse_float(t->input->value)) ||
		new_fov < 1 || new_fov > 179)
		return ("FOV index formatting error.\n\
		The field of view is a float between 1 and 179.");
	if (!t->in_scene)
		t->global_attributes->fov = new_fov;
	else if (!t->in_object)
		t->scene_attributes->fov = new_fov;
	else if (t->in_object)
		t->object_attributes->fov = new_fov;
	if (t->in_object && t->current_type != T_CAMERA)
		return ("FOV (field of view) attribute only applicable to cameras.");
	return (NULL);
}

char	*parse_intensity(t_parse_tools *t)
{
	float	new_intensity;

	new_intensity = NAN;
	if (isnan(new_intensity = parse_float(t->input->value)) ||
		new_intensity < 0)
		return ("Intensity index formatting error.\
		Intensity is a positive float.");
	if (!t->in_scene)
		t->global_attributes->intensity = new_intensity;
	else if (!t->in_object)
		t->scene_attributes->intensity = new_intensity;
	else if (t->in_object)
		t->object_attributes->intensity = new_intensity;
	if (t->in_object && t->current_type != T_LIGHT)
		return ("Intensity attribute only applicable to lights.");
	return (NULL);
}

char	*parse_filter(t_parse_tools *t)
{
	ft_strtoupper(t->input->value);
	if (ft_strcmp(t->input->value, "BLACK AND WHITE") == 0)
		t->current_camera->filter = F_BW;
	else if (ft_strcmp(t->input->value, "SEPIA") == 0)
		t->current_camera->filter = F_SEPIA;
	else if (ft_strcmp(t->input->value, "DEUTAN") == 0)
		t->current_camera->filter = F_DEUTAN;
	return (NULL);
}

char	*read_normal_map(t_parse_tools *t)
{
	t_color			*normal_map;

	if (!t->input->value)
		return ("Invalid texture name");
	if (!check_file_ext(t->input->value, "BMP"))
		return ("Texture must be a bmp file.");
	if (!(normal_map = read_bmp(t->input->value,
		&t->current_object->normal_map_dim)))
		return (strerror(errno));
	t->current_object->normal_map_name = ft_strdup(t->input->value);
	t->current_object->normal_map = normal_map;
	return (NULL);
}
