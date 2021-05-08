/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:23:42 by talemari          #+#    #+#             */
/*   Updated: 2017/01/30 12:28:18 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Adds a new element to the front of the list.
*/

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *n)
{
	if (n)
	{
		n->next = *alst;
		*alst = n;
	}
}
