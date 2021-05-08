/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is_released.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 12:53:32 by talemari          #+#    #+#             */
/*   Updated: 2017/04/21 10:43:49 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdlib.h>

int		key_is_released(int keycode, t_data *data)
{
	if (!data)
		return (-1);
	if (keycode > 278)
		return (-2);
	data->key.key[keycode] = FALSE;
	return (0);
}
