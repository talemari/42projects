/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   photon_mapping_assist.cu                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 12:55:39 by talemari          #+#    #+#             */
/*   Updated: 2017/06/09 10:18:55 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.cuh"
#include "cuda_call.cuh"
#include <cuda_runtime.h>

/*
** Functions assiting PPM.
*/

void	perpare_memory(t_raytracing_tools *r)
{
	r->h_d_scene->photon_iteration = 1;
	gpu_errchk(cudaMallocHost(&r->rt_pixel_map, sizeof(t_color) *
		r->scene->res.y * r->scene->res.x));
	cudaMemcpy(r->rt_pixel_map, r->d_pixel_map, sizeof(t_color) *
		r->scene->res.y * r->scene->res.x, cudaMemcpyHostToHost);
	gpu_errchk(cudaMalloc(&(r->h_d_scene->photon_list),
		sizeof(t_photon) * PHOTON_BOUNCE_MAX * r->scene->photons_per_pass));
	cudaMemcpy(r->d_scene, r->h_d_scene, sizeof(t_scene),
		cudaMemcpyHostToDevice);
}

void	copy_1(t_raytracing_tools *r)
{
	cudaMemcpy(r->d_scene, r->h_d_scene, sizeof(t_scene),
		cudaMemcpyHostToDevice);
}

void	copy_2(t_raytracing_tools *r)
{
	cudaMemcpy(r->d_pixel_map, r->rt_pixel_map, sizeof(t_color) *
		r->scene->res.x * r->scene->res.y, cudaMemcpyHostToHost);
}

void	free_map_and_list(t_raytracing_tools *r)
{
	cudaFreeHost(r->rt_pixel_map);
	cudaFree(r->h_d_scene->photon_list);
}
