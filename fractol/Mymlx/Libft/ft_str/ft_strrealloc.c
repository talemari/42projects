/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 18:14:04 by talemari          #+#    #+#             */
/*   Updated: 2017/01/06 18:14:07 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strrealloc(char *ptr, size_t newsize)
{
	size_t		cursize;
	char		*newptr;

	if (!ptr)
		return ((char *)malloc(newsize));
	cursize = ft_strlen(ptr);
	if (newsize <= cursize)
		return (ptr);
	newptr = (char *)malloc(newsize);
	ft_strcpy(newptr, ptr);
	free(ptr);
	return (newptr);
}