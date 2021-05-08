/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_widget.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 11:43:06 by talemari          #+#    #+#             */
/*   Updated: 2017/06/05 11:43:21 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.cuh"
#include "gui.h"

GtkWidget	*get_widget(t_gtk_tools *g, char *widget_name)
{
	return (GTK_WIDGET(gtk_builder_get_object(GTK_BUILDER(g->builder),
														widget_name)));
}
