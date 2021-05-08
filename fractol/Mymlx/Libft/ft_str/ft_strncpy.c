/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:53:28 by talemari          #+#    #+#             */
/*   Updated: 2017/01/14 16:55:27 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Copies at most len characters from src into dst.
** If src is less than len characters long, the remainder of dst is filled
** with \0. Otherwise, dst is not terminated.
*/

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (src[i] && (i < len))
	{
		dst[i] = src[i];
		i++;
	}
	while (i < len)
		dst[i++] = '\0';
	return (dst);
}
