/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 15:15:30 by talemari          #+#    #+#             */
/*   Updated: 2017/04/21 10:12:38 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "mlx.h"

static void		init_key(t_key *key)
{
	int		i;

	i = 0;
	while (i < 279)
		key->key[i++] = FALSE;
}

void			set_data(t_data *data)
{
	data->target.mlx = mlx_init();
	data->target.win = mlx_new_window(data->target.mlx, WIDTH, HEIGHT,
			"wolf3d");
	data->target.img = mlx_new_image(data->target.mlx, WIDTH, HEIGHT);
	parse_map(data);
	data->ppos = (t_vec2d){2, 2};
	data->pdir = (t_vec2d){-1, 0};
	data->cplane = (t_vec2d){0, 0.66};
	init_key(&data->key);
}
