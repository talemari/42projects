/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:24:05 by talemari          #+#    #+#             */
/*   Updated: 2016/11/10 14:57:25 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Returns 1 if c is digit, 0 if not.
*/

#include "libft.h"

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}
