/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:04:46 by talemari          #+#    #+#             */
/*   Updated: 2016/11/10 15:19:02 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Puts the string s to the standard output follow by a newline.
*/

#include "libft.h"

void	ft_putendl(char const *s)
{
	ft_putstr(s);
	ft_putchar('\n');
}
