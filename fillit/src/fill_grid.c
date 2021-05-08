/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:21:28 by talemari          #+#    #+#             */
/*   Updated: 2017/12/15 14:14:04 by grota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

char		**fill_grid(int size)
{
	char		**grid;
	int			i;
	int			j;

	i = 0;
	if (!(grid = (char **)malloc(sizeof(char *) * size + 1)))
		return (NULL);
	while (i < size)
	{
		if (!(grid[i] = ft_strnew(size)))
			return (NULL);
		j = 0;
		while (j < size)
			grid[i][j++] = '.';
		i++;
	}
	grid[i] = NULL;
	return (grid);
}

void		grid_sizeplus(t_grid *grid)
{
	int		i;

	i = 0;
	while (i < grid->size)
		ft_strdel(&grid->grid[i++]);
	grid->size++;
	grid->grid = fill_grid(grid->size);
}
