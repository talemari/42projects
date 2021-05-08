/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 11:56:26 by talemari          #+#    #+#             */
/*   Updated: 2017/06/05 11:56:32 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rt.cuh"

/*
** Parses a float.
*/

float	parse_float(char *value)
{
	float	new_d;
	int		i;

	new_d = NAN;
	if (ft_charcount(value, ',') ||
		!((ft_charcount(value, '.') == 1) ||
		ft_charcount(value, '.') == 0))
		return (new_d);
	i = -1;
	while (value && value[++i])
		if (!((ft_isdigit(value[i]) || value[i] == '-' ||
			value[i] == '+') || value[i] == '.'))
			return (new_d);
	new_d = ft_atof(value);
	return (new_d);
}
