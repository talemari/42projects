/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:27:40 by talemari          #+#    #+#             */
/*   Updated: 2016/12/01 17:51:52 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Travereses lst and applies f to each link.
*/

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*p;

	if (!lst)
		return ;
	p = lst;
	while (p != NULL)
	{
		f(p);
		p = p->next;
	}
}
