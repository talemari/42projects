/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:15:37 by talemari          #+#    #+#             */
/*   Updated: 2016/11/10 15:13:46 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Frees the memory pointed to by ap with free, then sets it to NULL.
*/

#include "libft.h"

void	ft_memdel(void **ap)
{
	free(*ap);
	*ap = NULL;
}
