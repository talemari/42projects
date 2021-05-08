/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 12:11:46 by talemari          #+#    #+#             */
/*   Updated: 2017/02/13 12:49:47 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

int				main(int ac, char **av)
{
	t_data		data;

	if (ac != 2)
	{
		ft_putendl("Error : Incorect number of arguments.");
		ft_putendl("Usage : ./fractol \"fractol name\"");
		return (0);
	}
	if ((set_data(&data, av[1])) == FALSE)
		return (0);
	mlx_put_image_to_window(data.target.mlx, data.target.win,
			data.target.img, 0, 0);
	mlx_hook(data.target.win, 6, (1L << 6), mouse_motion, &data);
	mlx_mouse_hook(data.target.win, mouse_is_pressed, &data);
	mlx_key_hook(data.target.win, key_is_pressed, &data);
	mlx_loop(data.target.mlx);
}
