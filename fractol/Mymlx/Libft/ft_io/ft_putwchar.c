/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 17:17:05 by talemari          #+#    #+#             */
/*   Updated: 2017/01/06 14:02:15 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Writes the wide character c to the standard output.
*/

int	ft_putwchar(wchar_t c)
{
	return (ft_putwchar_fd(c, 1));
}
