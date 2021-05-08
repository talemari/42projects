/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:25:21 by talemari          #+#    #+#             */
/*   Updated: 2016/11/10 14:53:08 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Returns 1 if c isalpha or isdigit, else returns 0.
*/

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
