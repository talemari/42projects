/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_usage_exit.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 15:44:26 by talemari          #+#    #+#             */
/*   Updated: 2017/01/29 17:30:28 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Displays the usage string and exits with value 1.
*/

void	ft_display_usage_exit(char *usage)
{
	ft_putendl_fd(usage, 2);
	exit(1);
}
