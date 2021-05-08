/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 15:42:36 by talemari          #+#    #+#             */
/*   Updated: 2017/02/15 12:11:09 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>

static void	set_step_side(t_rc *ray)
{
	if (ray->rdir.x < 0)
	{
		ray->step.x = -1;
		ray->sdis.x = (ray->rpos.x - ray->mpos.x) * ray->ddis.x;
	}
	else
	{
		ray->step.x = 1;
		ray->sdis.x = (ray->mpos.x + 1.0 - ray->rpos.x) * ray->ddis.x;
	}
	if (ray->rdir.y < 0)
	{
		ray->step.y = -1;
		ray->sdis.y = (ray->rpos.y - ray->mpos.y) * ray->ddis.y;
	}
	else
	{
		ray->step.y = 1;
		ray->sdis.y = (ray->mpos.y + 1.0 - ray->rpos.y) * ray->ddis.y;
	}
}

static void	dda_go(t_rc *ray, t_map *map)
{
	while (ray->hit == FALSE)
	{
		if (ray->sdis.x < ray->sdis.y)
		{
			ray->sdis.x += ray->ddis.x;
			ray->mpos.x += ray->step.x;
			ray->side = FALSE;
		}
		else
		{
			ray->sdis.y += ray->ddis.y;
			ray->mpos.y += ray->step.y;
			ray->side = TRUE;
		}
		if (map->coord[ray->mpos.x][ray->mpos.y] > 0)
			ray->hit = TRUE;
	}
}

void		set_ray(t_data *data, int x)
{
	t_rc	*r;

	r = &data->ray;
	r->camx = 2 * x / (double)WIDTH - 1;
	r->rpos = (t_vec2d){data->ppos.x, data->ppos.y};
	r->rdir = (t_vec2d){data->pdir.x + data->cplane.x * r->camx,
						data->pdir.y + data->cplane.y * r->camx};
	r->mpos = (t_vec2i){(int)r->rpos.x, (int)r->rpos.y};
	r->ddis.x = sqrt(1 + (r->rdir.y * r->rdir.y) / (r->rdir.x * r->rdir.x));
	r->ddis.y = sqrt(1 + (r->rdir.x * r->rdir.x) / (r->rdir.y * r->rdir.y));
	r->hit = FALSE;
	r->side = FALSE;
	set_step_side(r);
	dda_go(r, &data->map);
	if (r->side == FALSE)
		r->wdis = (r->mpos.x - r->rpos.x + (1 - r->step.x) / 2) / r->rdir.x;
	else
		r->wdis = (r->mpos.y - r->rpos.y + (1 - r->step.y) / 2) / r->rdir.y;
}
