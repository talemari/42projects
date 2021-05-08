/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:36:13 by talemari          #+#    #+#             */
/*   Updated: 2017/04/21 10:24:14 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdlib.h>
#include "mlx.h"
#include "mlx_event_macro.h"
#include <stdio.h>

int		main(void)
{
	t_data	data;

	set_data(&data);
	mlx_hook(data.target.win, KEYPRESS, KEYPRESSMASK, key_is_pressed, &data);
	mlx_hook(data.target.win, KEYRELEASE, KEYRELEASEMASK, key_is_released,
			&data);
	mlx_loop_hook(data.target.mlx, main_loop, &data);
	mlx_loop(data.target.mlx);
}
