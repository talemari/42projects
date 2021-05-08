/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_pushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 15:02:03 by talemari          #+#    #+#             */
/*   Updated: 2017/04/05 12:08:04 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Adds a t_input n to the end of t_input input.
*/

#include "../../inc/rt.cuh"

void	input_pushback(t_input **input, t_input *n)
{
	t_input	*ptr;

	if (n)
	{
		if (!(*input))
			*input = n;
		else
		{
			ptr = *input;
			while (ptr->next)
				ptr = ptr->next;
			ptr->next = n;
		}
		n->next = NULL;
	}
}
