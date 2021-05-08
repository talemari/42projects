/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:13:38 by talemari          #+#    #+#             */
/*   Updated: 2017/01/16 13:13:40 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Sets default values in the t_env structure.
*/

void	init_env(t_env *d, char *format)
{
	d->f = format;
	d->s = NULL;
	d->byte_count = 0;
	d->null_char = 0;
}
