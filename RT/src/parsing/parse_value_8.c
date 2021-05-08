/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_value_8.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:18:43 by talemari          #+#    #+#             */
/*   Updated: 2017/06/05 12:12:35 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rt.cuh"

/*
** Contains functions for parsing each value based on token.
*/

char	*read_material_file(t_parse_tools *t)
{
	(void)t;
	rt_file_warning(t, "Read material file: feature not yet available.");
	return (NULL);
}

char	*hashtag(t_parse_tools *t)
{
	rt_file_warning(t, "Ingore line.");
	return (NULL);
}

char	*invalid_token(t_parse_tools *t)
{
	(void)t;
	return ("Invalid token.");
}
