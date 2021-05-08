/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:18:09 by talemari          #+#    #+#             */
/*   Updated: 2017/01/06 15:20:02 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates memory for and returns a string of size size,
** with all characters initilized at \0.
** Returns NULL if allocation fails.
*/

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = ft_memalloc(size + 1)))
		return (NULL);
	ft_bzero(str, size);
	return (str);
}
