/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 15:54:43 by talemari          #+#    #+#             */
/*   Updated: 2017/01/10 14:24:24 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Computes and returns the length of a wide character string.
** Excludes the null temrinating character.
*/

#include "libft.h"

size_t	ft_wstrlen(const wchar_t *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		++i;
	return (i);
}
