/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 14:20:07 by talemari          #+#    #+#             */
/*   Updated: 2017/06/08 20:53:04 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rt.cuh"

static void	free_cameras(t_camera *cams);
static void	free_lights(t_light *lights);
static void	free_objects(t_object *objs);

/*
** Frees the t_scene linked list and all substructures.
*/

void		free_scene(t_scene *scene)
{
	free(scene->name);
	if (scene->cameras)
		free_cameras(scene->cameras);
	scene->cameras = NULL;
	if (scene->lights)
		free_lights(scene->lights);
	scene->lights = NULL;
	if (scene->objects)
		free_objects(scene->objects);
	scene->objects = NULL;
	scene = NULL;
}

static void	free_cameras(t_camera *cams)
{
	t_camera	*tmp;

	while (cams->prev)
		cams = cams->prev;
	while (cams)
	{
		tmp = cams;
		if (cams->name)
			free(cams->name);
		cams = cams->next;
		free(tmp);
		tmp = NULL;
	}
}

static void	free_lights(t_light *lights)
{
	t_light	*tmp;

	while (lights)
	{
		tmp = lights;
		if (lights->name)
			free(lights->name);
		lights = lights->next;
		free(tmp);
		tmp = NULL;
	}
}

static void	free_objects(t_object *objs)
{
	t_object	*tmp;

	while (objs)
	{
		tmp = objs;
		if (objs->name)
			free(objs->name);
		if (objs->texture_name)
			free(objs->texture_name);
		if (objs->normal_map_name)
			free(objs->normal_map_name);
		objs = objs->next;
		free(tmp);
		tmp = NULL;
	}
}
