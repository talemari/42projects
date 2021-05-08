/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 13:40:58 by talemari          #+#    #+#             */
/*   Updated: 2017/01/06 18:10:30 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_next_nbr(const char *line, int *res)
{
	static int		i = 0;

	while (ft_isnumeric(line[i]) == FALSE && line[i])
		i++;
	if (ft_isnumeric(line[i]) == FALSE)
		return ((i = 0));
	*res = ft_atoi(&line[i]);
	while (ft_isnumeric(line[i]) == TRUE && line[i])
		i++;
	return (1);
}