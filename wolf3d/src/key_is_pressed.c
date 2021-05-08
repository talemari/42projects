/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is_pressed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 20:10:17 by talemari          #+#    #+#             */
/*   Updated: 2017/04/21 10:49:47 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdlib.h>

int		key_is_pressed(int keycode, t_data *data)
{
	if (!data)
		return (-1);
	if (keycode > 278)
		return (-2);
	if (keycode == KEY_Q)
		exit(EXIT_SUCCESS);
	else
		data->key.key[keycode] = TRUE;
	return (0);
}
