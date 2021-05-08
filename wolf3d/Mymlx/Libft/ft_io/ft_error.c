/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 15:37:37 by talemari          #+#    #+#             */
/*   Updated: 2017/05/18 15:56:10 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Puts the error message on the error output and returns 0.
*/

#include "libft.h"

int	ft_error(char *error_msg)
{
	ft_putendl_fd(error_msg, 2);
	return (0);
}
