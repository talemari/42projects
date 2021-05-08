/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is_pressed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 16:33:09 by talemari          #+#    #+#             */
/*   Updated: 2017/01/06 18:07:11 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <stdlib.h>

int		key_is_pressed(int keycode, void *param)
{
	if (keycode == 65307)
		exit(1);
	if (keycode >= 65430 && keycode <= 65433)
		trigger_rotation(keycode, param);
	if (keycode >= 65361 && keycode <= 65364)
		trigger_translation(keycode, param);
	if (keycode == 97 || keycode == 119 || keycode == 100 || keycode == 115)
		trigger_scaling(keycode, param);
	return (0);
}
