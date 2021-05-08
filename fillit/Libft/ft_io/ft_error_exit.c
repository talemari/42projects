/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 11:41:29 by talemari          #+#    #+#             */
/*   Updated: 2017/05/18 15:56:01 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Puts the error message on the error output and exits the program.
*/

#include "libft.h"

void	ft_error_exit(char *error_msg)
{
	ft_putendl_fd(error_msg, 2);
	exit(1);
}
