/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymlx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 17:31:37 by talemari          #+#    #+#             */
/*   Updated: 2017/01/17 11:51:46 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYMLX_H
# define MYMLX_H

# include "libft.h"

# define BLUE 0x000000FF
# define RED 0x00FF0000
# define WHITE 0x00FFFFFF
# define BLACK 0x00000000
# define GREEN 0x00008000
# define BROWN 0x00A52A2A
# define TEAL 0x0000FFFF
# define PURPLE 0x00800080
# define YELLOW 0x00FFFF00
# define MAGENTA 0x00FF00FF

typedef struct	s_vec3f
{
	float		x;
	float		y;
	float		z;
}				t_vec3f;

typedef struct	s_vec3i
{
	int			x;
	int			y;
	int			z;
}				t_vec3i;

typedef struct	s_vec2d
{
	double		x;
	double		y;
}				t_vec2d;

typedef struct	s_vec2f
{
	float		x;
	float		y;
}				t_vec2f;

typedef struct	s_vec2i
{
	int			x;
	int			y;
}				t_vec2i;

typedef struct	s_mat1x3f
{
	float		c[3];
}				t_mat1x3f;

typedef struct	s_mat3x3f
{
	float		v[3][3];
}				t_mat3x3f;

typedef struct	s_mat4x4f
{
	float		v[4][4];
}				t_mat4x4f;

typedef struct	s_color
{
	int			t;
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_triangle
{
	t_vec2i		pos1;
	t_vec2i		pos2;
	t_vec2i		pos3;
}				t_triangle;

typedef struct	s_target
{
	void	*mlx;
	void	*img;
	void	*win;
	t_vec2i	size;
}				t_target;

typedef struct	s_dot
{
	t_vec2i		size;
	t_vec3f		**coord;
	int			seg_size;
}				t_dot;

int				mm_color_to_hex(t_color color);
int				mm_vec2fcmp(t_vec2f vec1, t_vec2f vec2);
t_color			mm_hex_to_color(int color);
t_mat1x3f		mat1x3f(t_vec3f vec);
t_mat3x3f		mat3x3f(t_mat1x3f c01, t_mat1x3f c02, t_mat1x3f c03);
t_mat3x3f		mm_mat_mult3x3(t_mat3x3f mat1, t_mat3x3f mat2);
t_mat3x3f		mm_mat_ortho_projection(void);
t_mat4x4f		mm_mat_rotation_x(float a);
t_mat4x4f		mm_mat_rotation_y(float a);
t_mat4x4f		mm_mat_rotation_z(float a);
t_mat3x3f		mm_mat_rotation_iso(void);
t_mat4x4f		mm_mat_scale(t_vec3f vec);
t_mat4x4f		mm_mat_translation(t_vec3f vec);
t_mat4x4f		mm_mat_mult4x4(t_mat4x4f mat1, t_mat4x4f mat2);
t_vec2f			mm_3d_to_ortho(t_vec3f vec);
t_vec2f			vec2f(float x, float y);
t_vec2i			vec2i(int x, int y);
t_vec3i			vec3i(int x, int y, int z);
t_vec3f			mm_mat4x4_mult_vec3f(t_vec3f v, t_mat4x4f m);
t_vec3f			mm_vec_multi_mat(t_vec3f vec, t_mat3x3f m);
t_vec3f			vec3f(float x, float y, float z);
void			mm_dotcpy(const t_dot src, t_dot *dst);
void			mm_line(t_target target, t_vec2i beg, t_vec2i end,
						t_color color);
void			mm_pixel_put(t_target target, t_vec2i pos, t_color color,
							t_bool img);
void			mm_pixel_put_img(void *img, t_vec2i size,
								t_vec2i pos, t_color color);
void			mm_putdot(t_dot dots);
void			mm_triangle(t_target target, t_triangle triangle,
							t_color color);

#endif
