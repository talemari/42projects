/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 13:54:34 by grota             #+#    #+#             */
/*   Updated: 2017/12/15 14:18:03 by grota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

int		ft_shape_exists(unsigned int *i)
{
	while (*i > 1)
	{
		if (*i == 4369 || *i == 15 || *i == 113 || *i == 71 || *i == 39 ||
				*i == 114 || *i == 562 || *i == 305 || *i == 785 || *i == 547 ||
				*i == 99 || *i == 54 || *i == 561 || *i == 306 || *i == 51 ||
				*i == 802 || *i == 23 || *i == 275 || *i == 116)
			return (1);
		*i = *i >> 1;
	}
	return (0);
}

void	ft_check_file(unsigned int *tab)
{
	size_t	i;

	i = 0;
	//if (!tab || tab[26] != 0)
	//	ft_error_exit("error : no tab");
	while (i < 26 && tab[i] != 0)
	{
		if (ft_shape_exists(tab + i) == 0)
			ft_error_exit("error : One shape doesnt exist");
		i++;
	}
}

void	ft_check_lines(char *str)
{
	size_t		i;
	size_t		hashcount;

	i = 0;
	hashcount = 0;
	if (str[4] != '\n' || str[9] != '\n' || str[14] != '\n' || str[19] != '\n')
		ft_error_exit("error : Format error.");
	while (str[i])
	{
		if (str[i] == '#')
			hashcount++;
		i++;
	}
	if (hashcount != 4)
		ft_error_exit("error : Hash error.");
}
