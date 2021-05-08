/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:34:23 by talemari          #+#    #+#             */
/*   Updated: 2016/11/10 15:40:26 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Applies f to each character in the string s, which are passed by address
** and can thus be modified within the function.
*/

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	if (s && f && *f)
		while (s && *s)
			f(s++);
}
