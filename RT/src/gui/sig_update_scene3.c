/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_update_scene3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 16:46:48 by talemari          #+#    #+#             */
/*   Updated: 2017/06/08 12:46:09 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.cuh"
#include "gui.h"

void	*sig_update_is_aa(GtkWidget *check_box, t_gtk_tools *g)
{
	g->r->scene->is_aa = gtk_toggle_button_get_active(
		GTK_TOGGLE_BUTTON(check_box)) + 1;
	(g->updating_gui) ? 0 : scene_render_sig(g);
	return (NULL);
}

void	*sig_update_is_anaglyph(GtkWidget *check_box, t_gtk_tools *g)
{
	g->r->scene->is_3d = gtk_toggle_button_get_active(
		GTK_TOGGLE_BUTTON(check_box));
	if (g->r->scene->is_3d)
		g->r->update.anaglyph = 2;
	else
	{
		g->r->scene->cameras->filter = F_NONE;
		g->r->update.cameras = 1;
	}
	(g->updating_gui) ? 0 : scene_render_sig(g);
	return (NULL);
}

void	*sig_update_is_raytracing(GtkWidget *check_box, t_gtk_tools *g)
{
	g->r->scene->is_raytracing = gtk_toggle_button_get_active(
		GTK_TOGGLE_BUTTON(check_box));
	(g->updating_gui) ? 0 : scene_render_sig(g);
	return (NULL);
}

void	*sig_update_is_cartoon(GtkWidget *check_box, t_gtk_tools *g)
{
	g->r->scene->is_cartoon_effect = gtk_toggle_button_get_active(
		GTK_TOGGLE_BUTTON(check_box));
	(g->updating_gui) ? 0 : scene_render_sig(g);
	return (NULL);
}
