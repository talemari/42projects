/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 15:01:54 by grota             #+#    #+#             */
/*   Updated: 2017/12/15 15:02:24 by grota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"
#include <math.h>

void	ft_inttocoord(unsigned int n, t_minos *link)
{
	int			x_zero;
	int			i;
	size_t		j;

	i = 0;
	j = 0;
	while ((n & 1) != 1)
	{
		n = n >> 1;
		i++;
	}
	x_zero = i++;
	n = n >> 1;
	while (i < 16 && n != 0)
	{
		while ((n & 1) != 1 && n != 0)
		{
			n = n >> 1;
			i++;
		}
		link->coord[j++] = (t_vec2i){(i % 4) - x_zero, i / 4};
		n = n >> 1;
		i++;
	}
}

void	ft_tabtolist(unsigned int *tab, t_minos **lst)
{
	size_t		i;
	t_minos		*tmp;

	i = 0;
	tmp = *lst;
	while (i < 26 && tab[i])
	{
		ft_inttocoord(tab[i], tmp);
		tmp->letter = 'A' + i;
		tmp->isplaced = FALSE;
		if (!(tmp->next = (t_minos*)malloc(sizeof(t_minos))))
			ft_error_exit("error");
		tmp->first = *lst;
		tmp = tmp->next;
		i++;
	}
	tmp->next = NULL;
}

int		ft_min_square(unsigned int *tab)
{
	int		nb_pieces;

	nb_pieces = 0;
	while (nb_pieces < 26 && tab[nb_pieces] != 0)
		nb_pieces++;
	while (sqrt(nb_pieces) == 0)
		nb_pieces--;
	return (2 * sqrt(nb_pieces));
}
