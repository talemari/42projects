/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:04:01 by talemari          #+#    #+#             */
/*   Updated: 2017/03/18 16:49:32 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocated sufficient memory for a copy of the string s1, does the copy,
** and returns a pointer to it. The pointer may subsequendly be used as an
** argument to the function free(3).
*/

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*new;

	if (!(new = (char*)ft_memalloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (NULL);
	return (ft_strcpy(new, src));
}
