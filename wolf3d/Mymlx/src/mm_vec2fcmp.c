/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_vec2fcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 13:32:19 by talemari          #+#    #+#             */
/*   Updated: 2017/01/03 14:39:08 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

int		mm_vec2fcmp(t_vec2f vec1, t_vec2f vec2)
{
	if (vec1.y < vec2.y || (vec1.y == vec2.y && vec1.x < vec2.x))
		return (1);
	if (vec1.y == vec2.y && vec1.x == vec2.x)
		return (0);
	else
		return (-1);
}
