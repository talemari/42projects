/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 15:30:58 by talemari          #+#    #+#             */
/*   Updated: 2017/04/21 10:44:58 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>

static void		translation(t_data *d)
{
	t_vec2d		*ppos;
	t_vec2d		*pdir;
	t_map		*map;

	ppos = &d->ppos;
	pdir = &d->pdir;
	map = &d->map;
	if (d->key.key[KEY_W] == TRUE)
	{
		if (map->coord[(int)(ppos->x + pdir->x * MS)][(int)ppos->y] == FALSE)
			ppos->x += pdir->x * MS;
		if (map->coord[(int)ppos->x][(int)(ppos->y + pdir->y * MS)] == FALSE)
			ppos->y += pdir->y * MS;
	}
	else if (d->key.key[KEY_S] == TRUE)
	{
		if (map->coord[(int)(ppos->x - pdir->x * MS)][(int)ppos->y] == FALSE)
			ppos->x -= pdir->x * MS;
		if (map->coord[(int)ppos->x][(int)(ppos->y - pdir->y * MS)] == FALSE)
			ppos->y -= pdir->y * MS;
	}
}

static void		rotation(t_data *d)
{
	double		rspeed;
	double		odir;
	double		oplane;

	rspeed = RS;
	if (d->key.key[KEY_D] == TRUE)
	{
		oplane = d->cplane.x;
		odir = d->pdir.x;
		d->pdir.x = d->pdir.x * cos(-rspeed) - d->pdir.y * sin(-rspeed);
		d->pdir.y = odir * sin(-rspeed) + d->pdir.y * cos(-rspeed);
		d->cplane.x = d->cplane.x * cos(-rspeed) - d->cplane.y * sin(-rspeed);
		d->cplane.y = oplane * sin(-rspeed) + d->cplane.y * cos(-rspeed);
	}
	else if (d->key.key[KEY_A] == TRUE)
	{
		oplane = d->cplane.x;
		odir = d->pdir.x;
		d->pdir.x = d->pdir.x * cos(rspeed) - d->pdir.y * sin(rspeed);
		d->pdir.y = odir * sin(rspeed) + d->pdir.y * cos(rspeed);
		d->cplane.x = d->cplane.x * cos(rspeed) - d->cplane.y * sin(rspeed);
		d->cplane.y = oplane * sin(rspeed) + d->cplane.y * cos(rspeed);
	}
}

void			player_movement(t_data *d)
{
	translation(d);
	rotation(d);
}
