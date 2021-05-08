/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_region_map.cu                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 17:15:06 by talemari          #+#    #+#             */
/*   Updated: 2017/06/08 16:57:40 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.cuh"
#include "cuda.h"
#include "../inc/cuda_call.cuh"

void	copy_region_map_tile(t_raytracing_tools *r, t_tile tile)
{
	int current_tile;

	if (r->scene->is_photon_mapping)
	{
		current_tile = (tile.id.y) * (tile.col) + (tile.id.x);
		gpu_errchk((cudaMemcpy(r->h_region_map[current_tile], r->d_region_map,
			sizeof(t_region) * tile.size * tile.size, cudaMemcpyDeviceToHost)));
	}
}

void	get_region_map_tile(t_raytracing_tools *r, t_tile tile)
{
	int current_tile;

	if (r->scene->is_photon_mapping)
	{
		current_tile = (tile.id.y) * (tile.col) + (tile.id.x);
		gpu_errchk((cudaMemcpy(r->d_region_map, r->h_region_map[current_tile],
			sizeof(t_region) * tile.size * tile.size, cudaMemcpyHostToDevice)));
	}
}

__device__
void	update_region_map(t_raytracing_tools *r, t_ray *cam_ray)
{
	if (r->scene->is_photon_mapping && !v_isnan(cam_ray->hit))
	{
		r->d_region_map->hit_pt = cam_ray->hit;
		r->d_region_map->ray_dir = cam_ray->dir;
		r->d_region_map->normal = v_scale(cam_ray->nhit, cam_ray->n_dir);
		r->d_region_map->kd = r->scene->objects[cam_ray->hit_obj].kd;
	}
}
