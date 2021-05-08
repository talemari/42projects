/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printgrid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 15:01:20 by grota             #+#    #+#             */
/*   Updated: 2017/12/15 15:01:21 by grota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

void	ft_printgrid(char **grid)
{
	size_t	i;

	i = 0;
	while (grid[i])
		ft_putendl(grid[i++]);
}