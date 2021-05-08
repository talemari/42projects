/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 10:38:10 by talemari          #+#    #+#             */
/*   Updated: 2017/04/21 10:46:10 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "mymlx.h"
# include "mlx_event_macro.h"

# define LINE_LENGHT 20
# define MS 0.2
# define RS 3.14 / 40
# define WIDTH 800
# define HEIGHT 600
# define KEY_Q 113
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100

typedef struct		s_rc
{
	t_vec2d			rpos;
	t_vec2d			rdir;
	t_vec2d			sdis;
	t_vec2d			ddis;
	t_vec2i			mpos;
	t_vec2i			step;
	double			wdis;
	double			camx;
	t_bool			hit;
	t_bool			side;
}					t_rc;

typedef struct		s_map
{
	int				**coord;
	t_vec2i			size;
}					t_map;

typedef struct		s_key
{
	t_bool			key[279];
}					t_key;

typedef struct		s_data
{
	t_vec2i			size;
	t_target		target;
	t_vec2d			ppos;
	t_vec2d			pdir;
	t_vec2d			cplane;
	double			time;
	double			ptime;
	double			ftime;
	double			mspeed;
	double			rspeed;
	t_map			map;
	t_rc			ray;
	t_key			key;
}					t_data;

int					key_is_pressed(int keycode, t_data *data);
int					key_is_released(int keycode, t_data *data);
int					main_loop(t_data *data);
void				draw_img(t_data *data);
void				parse_map(t_data *data);
void				player_movement(t_data *d);
void				putmap(t_map map);
void				redraw(t_data *data);
void				set_data(t_data *data);
void				set_ray(t_data *data, int x);
void				store_map(char **g, t_map *map);
#endif
