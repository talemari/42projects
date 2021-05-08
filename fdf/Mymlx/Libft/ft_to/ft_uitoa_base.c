/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:29:54 by talemari          #+#    #+#             */
/*   Updated: 2017/01/10 16:04:43 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Converts unsigned long integer value into an array in base base.
*/

char	*ft_uitoa_base(uintmax_t value, int base)
{
	char			*result;
	int				i;
	uintmax_t		n;

	if (base < 2)
		return (0);
	n = value;
	i = 1;
	while ((n /= base) >= 1)
		i++;
	if (!(result = (char *)malloc(i + 1)))
		return (NULL);
	result[i] = '\0';
	n = value;
	while (i--)
	{
		result[i] = (n % base) < 10 ? n % base + '0' : n % base + 'A' - 10;
		n /= base;
	}
	return (result);
}
