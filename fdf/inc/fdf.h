/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 13:20:58 by talemari          #+#    #+#             */
/*   Updated: 2017/01/17 12:51:46 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "Mymlx/mymlx.h"

# define LINE_LENGHT 20
# define WIDTH 1280
# define HEIGHT 1280
# define DEFAULT_ROTATION 3.14 / 20
# define DEFAULT_TRANSLATION 50
# define DEFAULT_SCALING 0.1
# define KEYPRESS 2
# define KEYPRESSMASK (1L<<0)

typedef struct		s_data
{
	t_vec2i			size;
	t_vec2f			scale;
	t_target		target;
	t_dot			dots;
	t_dot			base;
	int				seg_size;
}					t_data;

int					key_is_pressed(int keycode, void *param);
void				add_dot(t_dot **dots, t_vec2i pos, int zvalue);
void				store_dots(char **g, t_dot *dots);
void				set_data(char **g, t_data *data);
t_vec3i				**vec3i_tab_dup(t_vec3i **tab, t_vec2i size);
void				fdf_to_iso(const t_dot base, t_dot *dots);
void				draw_img(t_data data);
void				trigger_rotation(int keycode, void *data);
void				trigger_scaling(int keycode, t_data *data);
void				trigger_translation(int keycode, void *data);
#endif
