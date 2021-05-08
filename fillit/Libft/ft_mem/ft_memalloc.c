/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:08:33 by talemari          #+#    #+#             */
/*   Updated: 2017/01/16 12:56:39 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Using malloc, allocates memory of size size and returns a pointer to it.
** The allocated memory is initialized at 0.
*/

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*p;

	if (!(p = malloc(size)))
		return (NULL);
	return (ft_memset(p, 0, size));
}
