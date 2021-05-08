/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_color_to_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 14:16:36 by talemari          #+#    #+#             */
/*   Updated: 2017/01/06 17:33:08 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

static void		hex_fil(int *base_hex)
{
	base_hex[0] = 0x0;
	base_hex[1] = 0x1;
	base_hex[2] = 0x2;
	base_hex[3] = 0x3;
	base_hex[4] = 0x4;
	base_hex[5] = 0x5;
	base_hex[6] = 0x6;
	base_hex[7] = 0x7;
	base_hex[8] = 0x8;
	base_hex[9] = 0x9;
	base_hex[10] = 0xA;
	base_hex[11] = 0xB;
	base_hex[12] = 0xC;
	base_hex[13] = 0xD;
	base_hex[14] = 0xE;
	base_hex[15] = 0xF;
}

int				mm_color_to_hex(t_color color)
{
	int		base_hex[16];
	int		res;
	int		tmp;

	hex_fil(base_hex);
	res = base_hex[color.b % 16];
	res = (res * 0x10) + base_hex[(color.b / 16) % 16];
	res = (res * 0x10) + base_hex[color.g % 16];
	res = (res * 0x10) + base_hex[(color.g / 16) % 16];
	res = (res * 0x10) + base_hex[color.r % 16];
	res = (res * 0x10) + base_hex[(color.r / 16) % 16];
	res = (res * 0x10) + base_hex[color.t % 16];
	res = (res * 0x10) + base_hex[(color.t / 16) % 16];
	while (res != 0)
	{
		tmp = tmp * 0x10;
		tmp = tmp + res % 0x10;
		res = res / 0x10;
	}
	return (tmp);
}
