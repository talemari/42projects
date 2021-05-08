/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:28:38 by talemari          #+#    #+#             */
/*   Updated: 2016/11/10 14:53:34 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Tests for an ASCII character. Returns 1 if true, 0 is false.
*/

#include "libft.h"

int	ft_isascii(int c)
{
	return (0 <= c && c <= 127);
}
