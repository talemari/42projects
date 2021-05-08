/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_is_pressed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:36:47 by talemari          #+#    #+#             */
/*   Updated: 2017/02/14 12:08:29 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

int		mouse_is_pressed(int keycode, int x, int y, void *param)
{
	if (keycode == 1 || keycode == 2 || keycode == 4 || keycode == 5)
		trigger_zoom(keycode, param, (t_vec2i){x, y});
	ft_printf("%d\n", keycode);
	return (0);
}
