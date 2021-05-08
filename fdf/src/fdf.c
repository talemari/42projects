/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:05:15 by talemari          #+#    #+#             */
/*   Updated: 2017/01/19 13:52:01 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "mlx.h"
#include "Mymlx/mymlx.h"

static	t_bool	puterror(char *err)
{
	ft_putstr("ERROR : ");
	ft_putendl(err);
	return (FALSE);
}

static t_bool	grid_check(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_isnumeric(str[i]) == FALSE && str[i] != ' ' && str[i] != '\n')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static char		**grid_parser(int fd)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	char	*str;
	char	**grid;

	ret = -1;
	str = NULL;
	while (ret != 0)
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) < 0)
			return (NULL);
		buf[ret] = '\0';
		if (grid_check(buf) == FALSE)
			return (NULL);
		str = ft_strrealloc(str, ft_strlen(str) + ft_strlen(buf) + 1);
		str = ft_strcat(str, buf);
	}
	grid = ft_strsplit(str, '\n');
	ft_strdel(&str);
	return (grid);
}

int				main(int ac, char **av)
{
	char		**grid;
	int			fd;
	t_data		data;

	if (ac != 2)
		return (puterror("Usage : fdf \"map name\""));
	if ((fd = open(av[1], O_RDONLY, O_NONBLOCK)) < 0)
		return (puterror(strerror(fd)));
	ft_putendl(" ");
	if ((grid = grid_parser(fd)) == NULL)
		return (puterror("Invalid map"));
	close(fd);
	set_data(grid, &data);
	draw_img(data);
	mlx_put_image_to_window(data.target.mlx, data.target.win, data.target.img, 0, 0);
	mlx_hook(data.target.win, KEYPRESS, KEYPRESSMASK, key_is_pressed, &data);
	mlx_loop(data.target.mlx);
}
