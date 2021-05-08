/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_triangle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 17:29:07 by talemari          #+#    #+#             */
/*   Updated: 2017/01/06 17:59:24 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

void	mm_triangle(t_target target, t_triangle triangle, t_color color)
{
	mm_line(target, triangle.pos1, triangle.pos2, color);
	mm_line(target, triangle.pos2, triangle.pos3, color);
	mm_line(target, triangle.pos3, triangle.pos1, color);
}
