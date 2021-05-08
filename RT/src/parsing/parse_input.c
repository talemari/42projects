/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 12:25:38 by talemari          #+#    #+#             */
/*   Updated: 2017/06/05 11:56:52 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rt.cuh"

/*
** Loops over token-value pairs and prepares the scene.
*/

char		*parse_input(t_parse_tools *t)
{
	char	*ret;

	t->input_head = t->input;
	while (t->input)
	{
		if ((ret = t->parse[t->input->token](t)))
			return (ret);
		t->input = t->input->next;
	}
	if (t->in_scene || t->in_object)
		return ("Brackets error");
	return (NULL);
}
