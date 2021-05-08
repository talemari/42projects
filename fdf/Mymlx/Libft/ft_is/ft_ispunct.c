/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispunct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 11:33:09 by talemari          #+#    #+#             */
/*   Updated: 2017/01/21 15:41:54 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Returns 1 if c is punctuation, 0 if not.
*/

#include "libft.h"

int	ft_ispunct(int c)
{
	return ((33 <= c && c <= 47) ||
			(58 <= c && c <= 64) ||
			(91 <= c && c <= 96) ||
			(123 <= c && c <= 126));
}