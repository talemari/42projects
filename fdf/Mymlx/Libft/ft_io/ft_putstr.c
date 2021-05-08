/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:01:33 by talemari          #+#    #+#             */
/*   Updated: 2016/11/10 15:24:24 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Writes the string s to the standard output.
*/

#include "libft.h"

void	ft_putstr(char const *s)
{
	write(1, s, ft_strlen(s));
}
