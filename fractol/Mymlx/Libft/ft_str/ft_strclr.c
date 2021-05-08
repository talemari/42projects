/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:29:32 by talemari          #+#    #+#             */
/*   Updated: 2016/12/28 10:59:54 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Assigns \0 to all chars of the string s.
*/

#include "libft.h"

void	ft_strclr(char *s)
{
	if (s)
		ft_bzero(s, ft_strlen(s));
}
