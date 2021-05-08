/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_address.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 19:07:14 by talemari          #+#    #+#             */
/*   Updated: 2017/01/15 17:56:20 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Gets the address for p conversions.
** p conversion results are always displayed in alternate form (# flag).
*/

int	get_address(t_env *d, t_arg *arg)
{
	arg->flags.hashtag = 1;
	arg->length = l;
	if (!get_unsigned_int(d, arg))
		return (0);
	return (1);
}
