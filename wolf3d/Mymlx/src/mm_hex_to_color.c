/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_color_convertto_color.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 11:56:32 by talemari          #+#    #+#             */
/*   Updated: 2017/01/06 17:33:56 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

t_color		mm_hex_to_color(int color)
{
	t_color		res;

	res.b = color % (0x100);
	res.b = (res.b % 0x10 + 0x01) * (res.b / 0x10 + 0x01) - 0x01;
	res.g = (color % 0x10000) / 0x100;
	res.g = (res.g % 0x10 + 0x01) * (res.g / 0x10 + 0x01) - 0x01;
	res.r = (color % 0x1000000) / 0x10000;
	res.r = (res.r % 0x10 + 0x01) * (res.r / 0x10 + 0x01) - 0x01;
	res.t = 0x00;
	return (res);
}
