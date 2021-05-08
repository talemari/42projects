/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:18:58 by talemari          #+#    #+#             */
/*   Updated: 2017/01/06 15:21:28 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Writes n \0 to the string s.
** If n is 0, ft_bzero does nothing.
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	if (n > 0)
		ft_memset(s, 0, n);
}
