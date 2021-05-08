/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:48:37 by talemari          #+#    #+#             */
/*   Updated: 2017/12/15 14:09:48 by grota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

static t_bool	check_tetro(t_grid *grid, t_minos tetro, t_vec2i pos)
{
	int		i;

	i = 0;
	if (grid->grid[pos.y][pos.x] != '.')
		return (FALSE);
	while (i <= 2)
	{
		if ((pos.y + tetro.coord[i].y >= grid->size ||
					pos.x + tetro.coord[i].x >= grid->size) ||
				grid->grid[pos.y + tetro.coord[i].y][pos.x + tetro.coord[i].x]
				!= '.')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static void		add_tetro(t_grid *grid, t_minos *tetro, t_vec2i pos)
{
	int		i;

	i = 0;
	grid->grid[pos.y][pos.x] = tetro->letter;
	while (i <= 2)
	{
		grid->grid[pos.y + tetro->coord[i].y][pos.x +
			tetro->coord[i].x] = tetro->letter;
		i++;
	}
	tetro->isplaced = TRUE;
}

static void		remove_tetro(t_grid *grid, t_minos *tetro, t_vec2i pos)
{
	int		i;

	i = 0;
	grid->grid[pos.y][pos.x] = '.';
	while (i <= 2)
	{
		grid->grid[pos.y + tetro->coord[i].y][pos.x +
			tetro->coord[i].x] = '.';
		i++;
	}
	tetro->isplaced = FALSE;
}

static t_bool	check_list(t_minos **tetro)
{
	t_minos		*tmp;

	tmp = *tetro;
	while (tmp)
	{
		if (tmp->isplaced == FALSE)
			return (FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}

t_bool			solver(t_minos *tetro, t_grid *grid)
{
	t_vec2i		pos;

	pos = (t_vec2i){-1, -1};
	if (check_list(&tetro->first))
		return (TRUE);
	while (++pos.y < grid->size)
	{
		while (++pos.x < grid->size)
		{
			if (check_tetro(grid, *tetro, pos))
			{
				add_tetro(grid, tetro, pos);
				if (!tetro->next)
					tetro = tetro->first;
				if (!solver(tetro->next, grid))
					remove_tetro(grid, tetro, pos);
				else
					return (TRUE);
			}
		}
		pos.x = -1;
	}
	return (FALSE);
}
