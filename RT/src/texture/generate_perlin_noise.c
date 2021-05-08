/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_perlin_noise.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 14:40:55 by talemari          #+#    #+#             */
/*   Updated: 2017/06/02 16:08:42 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.cuh"
#include <cuda_runtime.h>

int			*get_perm_array(void)
{
	int		*perm;
	int		i;
	int		j;
	int		t;

	if (!(perm = (int *)malloc(sizeof(int) * 255)))
		return (NULL);
	i = -1;
	while (++i < 255)
		perm[i] = i;
	i = -1;
	while (++i < 255)
	{
		j = i + rand() / (RAND_MAX / (255 - i) + 1);
		t = perm[j];
		perm[j] = perm[i];
		perm[i] = t;
	}
	return (perm);
}

float		interpolation(t_dpt2 real, float x, float y, float *vec)
{
	t_dpt2	smooth;
	float	c_x;
	float	c_y;

	real.x = x - (int)x;
	c_x = 3 * powf(real.x, 2.f) - 2 * powf(real.x, 3.f);
	smooth.x = vec[0] + c_x * (vec[1] - vec[0]);
	smooth.y = vec[2] + c_x * (vec[3] - vec[2]);
	real.y = y - (int)y;
	c_y = 3 * powf(real.y, 2.f) - 2 * powf(real.y, 3.f);
	return (smooth.x + c_y * (smooth.y - smooth.x));
}

float		*get_gradiant_array(void)
{
	float	unit;
	float	*gradiant;

	if (!(gradiant = (float *)malloc(sizeof(float) * 16)))
		return (NULL);
	unit = 1.0 / sqrt(2);
	gradiant[0] = unit;
	gradiant[1] = unit;
	gradiant[2] = -unit;
	gradiant[3] = unit;
	gradiant[4] = unit;
	gradiant[5] = -unit;
	gradiant[6] = -unit;
	gradiant[7] = -unit;
	gradiant[8] = 1;
	gradiant[9] = 0;
	gradiant[10] = -1;
	gradiant[11] = 0;
	gradiant[12] = 0;
	gradiant[13] = 1;
	gradiant[14] = 0;
	gradiant[15] = -1;
	return (gradiant);
}

float		get_perlin_at_pixel(t_dpt2 x, float res, int *p, float *grad)
{
	t_dpt2	real;
	float	vec[4];
	int		pts[4];

	x.x /= res;
	x.y /= res;
	pts[0] = p[(int)((int)x.x & 255) + p[(int)((int)x.y & 255)]] % 8;
	pts[1] = p[(int)((int)x.x & 255) + 1 + p[(int)((int)x.y & 255)]] % 8;
	pts[2] = p[(int)((int)x.x & 255) + p[(int)((int)x.y & 255) + 1]] % 8;
	pts[3] = p[(int)((int)x.x & 255) + 1 + p[(int)((int)x.y & 255) + 1]] % 8;
	real.x = x.x - (int)x.x;
	real.y = x.y - (int)x.y;
	vec[0] = grad[pts[0] * 2] * real.x + grad[pts[0] * 2 + 1] * real.y;
	real.x = x.x - ((int)x.x + 1);
	real.y = x.y - (int)x.y;
	vec[1] = grad[pts[1] * 2] * real.x + grad[pts[1] * 2 + 1] * real.y;
	real.x = x.x - (int)x.x;
	real.y = x.y - ((int)x.y + 1);
	vec[2] = grad[pts[2] * 2] * real.x + grad[pts[2] * 2 + 1] * real.y;
	real.x = x.x - ((int)x.x + 1);
	real.y = x.y - ((int)x.y + 1);
	vec[3] = grad[pts[3] * 2] * real.x + grad[pts[3] * 2 + 1] * real.y;
	return (interpolation(real, x.x, x.y, vec));
}

t_color		*generate_perlin_noise(t_vec3 *res)
{
	t_color		*map;
	t_dpt2		i;
	float		color;
	int			*perm;
	float		*grad;

	if (!(perm = get_perm_array()) || cudaMallocHost((void **)&map,
		(3 * res->x * res->y)) != 0 || !(grad = get_gradiant_array()))
		return (NULL);
	i.y = -1;
	while (++i.y < res->y)
	{
		i.x = -1;
		while (++i.x < res->x)
		{
			color = (get_perlin_at_pixel(i, res->z, perm, grad) + 0.5) * 255;
			color = ft_clampf(color, 0.0, 255.0);
			map[(int)(i.y * res->x + i.x)].r = color;
			map[(int)(i.y * res->x + i.x)].g = color;
			map[(int)(i.y * res->x + i.x)].b = color;
		}
	}
	free(perm);
	free(grad);
	return (map);
}
