/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_update_settings.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 11:23:26 by talemari          #+#    #+#             */
/*   Updated: 2017/06/08 12:25:10 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.cuh"
#include "gui.h"

void	settings_render_sig(t_gtk_tools *g)
{
	g->r->update.render = 1;
	if (g->win)
		gtk_widget_queue_draw(g->win);
}

void	*sig_update_tile_size(GtkWidget *spin_button, t_gtk_tools *g)
{
	while (g->r->rendering)
		;
	g->r->settings.tile_size =
		gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_button));
	return (NULL);
}

void	*sig_update_aa(GtkWidget *combo_box, t_gtk_tools *g)
{
	g->r->scene->is_aa =
		gtk_combo_box_get_active(GTK_COMBO_BOX(combo_box)) + 1;
	(g->updating_gui) ? 0 : settings_render_sig(g);
	return (NULL);
}

void	*sig_update_photon_count(GtkWidget *spin_button, t_gtk_tools *g)
{
	g->r->scene->photon_count =
		gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_button));
	(g->updating_gui) ? 0 : settings_render_sig(g);
	return (NULL);
}

void	*sig_update_font_size(GtkWidget *combo_box, t_gtk_tools *g)
{
	int				id;
	GtkStyleContext	*context;

	context = gtk_widget_get_style_context(GTK_WIDGET(
			gtk_builder_get_object(GTK_BUILDER(g->builder), "window_main")));
	id = gtk_combo_box_get_active(GTK_COMBO_BOX(combo_box));
	if (gtk_style_context_has_class(context, "bigfont"))
		gtk_style_context_remove_class(context, "bigfont");
	if (gtk_style_context_has_class(context, "smallfont"))
		gtk_style_context_remove_class(context, "smallfont");
	if (id == 0)
		gtk_style_context_add_class(context, "smallfont");
	else if (id == 2)
		gtk_style_context_add_class(context, "bigfont");
	return (NULL);
}
