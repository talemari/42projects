/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 11:53:17 by talemari          #+#    #+#             */
/*   Updated: 2017/04/17 12:36:29 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rt.cuh"

/*
** Adds new_object to the end of list t_objects.
*/

void	push_object(t_object **objects_head, t_object *new_object)
{
	t_object	*obj_ptr;

	if (new_object)
	{
		if (!(*objects_head))
			*objects_head = new_object;
		else
		{
			obj_ptr = *objects_head;
			while (obj_ptr->next)
				obj_ptr = obj_ptr->next;
			obj_ptr->next = new_object;
		}
		new_object->next = NULL;
	}
}
