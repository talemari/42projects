/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector2i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 19:45:07 by talemari          #+#    #+#             */
/*   Updated: 2017/01/06 17:53:55 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

t_vec2i		vec2i(int x, int y)
{
	t_vec2i	res;

	res.x = x;
	res.y = y;
	return (res);
}