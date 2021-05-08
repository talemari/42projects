/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 18:34:54 by talemari          #+#    #+#             */
/*   Updated: 2017/01/21 15:51:17 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Puts the uppercase chars in a char string to lowercase.
*/

void	ft_strtolower(char *s)
{
	int	i;

	i = -1;
	while (s && s[++i])
		ft_isupper(s[i]) ? s[i] = ft_tolower(s[i]) : 0;
}
