/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_percent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 16:34:37 by talemari          #+#    #+#             */
/*   Updated: 2017/01/15 15:55:43 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Gets a string with '%' for % type conversions.
*/

int	get_percent(t_arg *arg)
{
	if (!(arg->result = ft_ustrnew(1)))
		return (0);
	arg->result[0] = '%';
	return (1);
}
