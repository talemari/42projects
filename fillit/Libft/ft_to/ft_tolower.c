/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:53:56 by talemari          #+#    #+#             */
/*   Updated: 2016/11/10 16:31:13 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Convert a upper-case letter to the corresponding lower-case letter.
** Otherwise, the argument is returned unchanged.
*/

#include "libft.h"

int	ft_tolower(int c)
{
	if (ft_isupper(c))
		c += 32;
	return (c);
}
