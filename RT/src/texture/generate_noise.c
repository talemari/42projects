/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_noise.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 11:33:53 by talemari          #+#    #+#             */
/*   Updated: 2017/06/09 10:22:29 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.cuh"
#include <cuda_runtime.h>

t_color		*generate_noise(t_vec3 *res)
{
	t_color		*map;
	int			nb_pts;
	t_pt2		pos;

	if (cudaMallocHost((void **)&map, (3 * res->x * res->y)) != 0)
		ft_error_exit("cudaMallocHost error");
	ft_bzero(map, 3 * res->x * res->y);
	nb_pts = (res->x * res->y) * res->z / 100;
	while (nb_pts > 0)
	{
		pos.x = rand() % (int)res->x;
		pos.y = rand() % (int)res->y;
		while (map[pos.y * (int)res->x + pos.x].r == 255)
		{
			pos.x = rand() % (int)res->x;
			pos.y = rand() % (int)res->y;
		}
		map[pos.y * (int)res->x + pos.x].r = 255;
		map[pos.y * (int)res->x + pos.x].g = 255;
		map[pos.y * (int)res->x + pos.x].b = 255;
		nb_pts--;
	}
	return (map);
}
