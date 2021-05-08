/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:50:36 by talemari          #+#    #+#             */
/*   Updated: 2016/11/10 16:30:53 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Convert a lower-case letter to the corresponding upper-case letter.
** Otherwise, the argument is returned unchanged.
*/

#include "libft.h"

int	ft_toupper(int c)
{
	if (ft_islower(c))
		c -= 32;
	return (c);
}
