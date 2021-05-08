/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errno_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 11:27:12 by talemari          #+#    #+#             */
/*   Updated: 2017/03/18 15:52:03 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
** Displays error messsage based on errno on error output and exits.
*/

void	ft_errno_exit(void)
{
	ft_putendl_fd(strerror(errno), 2);
	exit(0);
}
