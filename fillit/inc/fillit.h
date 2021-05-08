/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 13:30:16 by grota             #+#    #+#             */
/*   Updated: 2017/12/12 16:33:33 by grota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUF_SIZE 21
# define TRUE 1
# define FALSE 0

# include "libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef int			t_bool;

typedef struct		s_vec2i
{
	int				x;
	int				y;
}					t_vec2i;

typedef struct		s_minos
{
	t_vec2i			coord[3];
	char			letter;
	t_bool			isplaced;
	struct s_minos	*next;
	struct s_minos	*first;
}					t_minos;

typedef struct		s_grid
{
	char			**grid;
	t_bool			check;
	int				size;
}					t_grid;

unsigned int		ft_strtobin(char *s);
unsigned int		*ft_filetotab(char **argv);
int					ft_shape_exists(unsigned int *i);
void				ft_check_file(unsigned int *tab);
void				ft_printtab(unsigned int *tab);
void				ft_inttocoord(unsigned int n, t_minos *link);
void				ft_tabtolist(unsigned int *tab, t_minos **lst);
void				ft_printlist(t_minos **lst);
int					ft_min_square(unsigned int *tab);
t_bool				solver(t_minos *tetro, t_grid *grid);
char				**fill_grid(int size);
void				ft_printgrid(char **grid);
void				grid_sizeplus(t_grid *grid);
void				ft_check_lines(char *str);
int					ft_bitx_isone(int a, int x);
void				ft_error_exit(char *str);

#endif
