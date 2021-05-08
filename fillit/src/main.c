/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 13:01:26 by grota             #+#    #+#             */
/*   Updated: 2017/12/12 16:48:32 by grota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

int		main(int argc, char **argv)
{
	unsigned int	*tab;
	t_minos			*lst;
	t_grid			grid;
	t_bool			boules;

	boules = FALSE;
	if (argc != 2 || !(lst = (t_minos*)malloc(sizeof(t_minos))))
		ft_error_exit("error");
	grid.size = 2;
	grid.grid = fill_grid(grid.size);
	tab = ft_filetotab(argv);
	ft_check_file(tab);
	ft_tabtolist(tab, &lst);
	while (!boules)
	{
		boules = solver(lst, &grid);
		if (!boules)
			grid_sizeplus(&grid);
	}
	ft_printgrid(grid.grid);
	return (0);
}
