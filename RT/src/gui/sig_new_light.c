/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_new_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 15:08:01 by talemari          #+#    #+#             */
/*   Updated: 2017/06/08 21:16:18 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.cuh"
#include "gui.h"

void	*sig_new_light(GtkWidget *widget, t_gtk_tools *g)
{
	t_light	*light;

	(void)widget;
	if (!(light = (t_light *)ft_memalloc(sizeof(t_light))))
		return (NULL);
	ft_bzero(light, sizeof(t_light));
	light->intensity = DEFAULT_INTENSITY;
	light->col = v_new(DEFAULT_COL_R, DEFAULT_COL_G, DEFAULT_COL_B);
	light->pos = v_new(DEFAULT_POS_X, DEFAULT_POS_Y, DEFAULT_POS_Z);
	light->dir = v_new(NAN, NAN, NAN);
	light->name = ft_strdup("New light");
	light->next = NULL;
	push_light(&(g->r->scene->lights), light);
	g->r->update.render = 1;
	g->r->update.lights = 2;
	update_grid_lights(g);
	gtk_widget_set_sensitive(get_widget(g, "ScrollWindowLight"), true);
	gtk_widget_set_sensitive(get_widget(g, "ButtonDeleteLight"), true);
	if (g->win)
		gtk_widget_queue_draw(g->win);
	return (NULL);
}
