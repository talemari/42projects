/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   photon_mapping_pass.cu                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 12:16:47 by talemari          #+#    #+#             */
/*   Updated: 2017/06/08 16:58:55 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.cuh"
#include "../../inc/cuda_call.cuh"
#include <cuda.h>

static void		init_photon_group(t_raytracing_tools *r, size_t photon_count,
				t_photon *init_photon_list);
static float	get_total_intensity(t_light *lights);

void			photon_mapping_pass(t_raytracing_tools *r)
{
	t_photon	*init_photon_list;
	int			photon_count;

	photon_count = r->scene->photons_per_pass;
	gpu_errchk(cudaMallocHost(&init_photon_list, sizeof(t_photon) *
		photon_count));
	init_photon_group(r, photon_count, init_photon_list);
	shoot_photon_wrapper(r, photon_count, init_photon_list);
	cudaFreeHost(init_photon_list);
}

static void		init_photon_group(t_raytracing_tools *r, size_t photon_count,
				t_photon *init_photon_list)
{
	t_light		*l_ptr;
	float		total_intensity;
	float		ratio;
	int			i;

	total_intensity = get_total_intensity(r->scene->lights);
	l_ptr = r->scene->lights;
	ratio = 0;
	i = -1;
	while (l_ptr)
	{
		if (v_isnan(l_ptr->pos))
		{
			l_ptr = l_ptr->next;
			continue ;
		}
		ratio += photon_count * l_ptr->intensity / total_intensity;
		while (++i < ratio)
		{
			init_photon_list[i].pos = l_ptr->pos;
			init_photon_list[i].col = vec_to_col(l_ptr->col);
			init_photon_list[i].n = v_new(NAN, NAN, NAN);
		}
		l_ptr = l_ptr->next;
	}
}

static float	get_total_intensity(t_light *lights)
{
	t_light		*l_ptr;
	float		total_intensity;

	l_ptr = lights;
	total_intensity = 0;
	while (l_ptr)
	{
		if (v_isnan(l_ptr->pos))
		{
			l_ptr = l_ptr->next;
			continue ;
		}
		total_intensity += l_ptr->intensity;
		l_ptr = l_ptr->next;
	}
	return (total_intensity);
}
