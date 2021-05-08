/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 15:57:12 by talemari          #+#    #+#             */
/*   Updated: 2017/06/08 13:57:55 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rt.cuh"
#include <cuda_runtime.h>

/*
** Frees an object and related allocated memory.
*/

static void	remove_object2(t_object **head, t_object *to_delete,
			t_object *prev);
static void	free_normal_map(t_object *to_delete);

void		free_object(t_object *to_delete)
{
	struct cuda_pointer_attributes	attributes;

	if (to_delete->name)
		free(to_delete->name);
	if (to_delete->texture)
	{
		if (cudaPointerGetAttributes(&attributes, to_delete->texture))
			ft_error_exit("Invalid device");
		if (attributes.type == cudaMemoryTypeHost)
			cudaFreeHost(to_delete->texture);
		else
			cudaFree(to_delete->texture);
		if (to_delete->texture_name)
			free(to_delete->texture_name);
	}
	if (to_delete->normal_map)
		free_normal_map(to_delete);
	free(to_delete);
}

static void	free_normal_map(t_object *to_delete)
{
	struct cuda_pointer_attributes	attributes;

	if (to_delete->normal_map_name)
		free(to_delete->normal_map_name);
	if (cudaPointerGetAttributes(&attributes, to_delete->normal_map))
		ft_error_exit("Invalid device");
	if (attributes.type == cudaMemoryTypeHost)
		cudaFreeHost(to_delete->normal_map);
	else
		cudaFree(to_delete->normal_map);
	if (to_delete->normal_map_name)
		free(to_delete->normal_map_name);
}

void		remove_object(t_object **head, t_object *to_delete)
{
	t_object	*prev;

	if (!head || !*head)
		return ;
	prev = *head;
	if (prev == to_delete)
	{
		*head = prev->next;
		free_object(to_delete);
		return ;
	}
	remove_object2(head, to_delete, prev);
}

static void	remove_object2(t_object **head, t_object *to_delete,
			t_object *prev)
{
	t_object	*tmp;

	if (prev->next)
	{
		tmp = prev->next;
		while (tmp && tmp != to_delete)
		{
			prev = prev->next;
			tmp = tmp->next;
		}
		if (tmp == to_delete)
		{
			prev->next = tmp->next;
			free_object(to_delete);
		}
	}
	else
	{
		free_object(to_delete);
		*head = NULL;
	}
}
