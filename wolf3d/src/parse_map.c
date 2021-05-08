/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 09:44:26 by talemari          #+#    #+#             */
/*   Updated: 2017/04/21 10:49:38 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void		parse_map(t_data *data)
{
	int		fd;
	char	*l;
	char	**tab;
	int		i;
	int		j;

	data->map.coord = (int **)malloc(sizeof(int *) * 15);
	fd = open("map.msp", O_RDONLY);
	i = 0;
	while (get_next_line(fd, &l))
	{
		j = 0;
		data->map.coord[i] = (int *)malloc(sizeof(int *) * 15);
		tab = ft_strsplit(l, ' ');
		while (j < 15)
		{
			data->map.coord[i][j] = ft_atoi(tab[j]);
			j++;
		}
		ft_freetab(tab);
		ft_strdel(&l);
		i++;
	}
	ft_strdel(&l);
}
