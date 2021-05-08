/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:59:38 by talemari          #+#    #+#             */
/*   Updated: 2016/11/10 18:24:35 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Copies len bytes from string src to string dst.
** The two srings may overlap.
** The copy is always done is a non-destructive manner.
** Returns the original value of dst
*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	i = 0;
	if (len && src > dst)
		while (i < (int)len)
			((char *)dst)[i++] = *(char *)src++;
	else
	{
		i = (int)len;
		while (--i >= 0)
			((char *)dst)[i] = ((char *)src)[i];
	}
	return (dst);
}
