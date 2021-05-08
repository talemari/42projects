/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 17:15:30 by grota             #+#    #+#             */
/*   Updated: 2017/12/12 16:48:34 by grota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned int	ft_strtobin(char *s)
{
	size_t			i;
	unsigned int	item;
	unsigned int	x;

	i = 0;
	item = 0;
	x = 0;
	ft_check_lines(s);
	while (s[i])
	{
		if (s[i] == '#')
			item = ft_bitx_isone(item, x);
		if (s[i] == '#' || s[i] == '.')
			x++;
		if (s[i] != '#' && s[i] != '.' && s[i] != '\n')
			return (0);
		i++;
	}
	if (x != 16)
		return (0);
	return (item);
}

unsigned int	*ft_filetotab(char **argv)
{
	int				fd;
	int				ret;
	unsigned int	*items;
	size_t			i;
	char			*buf;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (!(buf = ft_strnew(BUF_SIZE)) || fd == -1 ||
			!(items = (unsigned int*)malloc(sizeof(*items) * 26)))
		ft_error_exit("error");
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		items[i] = ft_strtobin(buf);
		if (items[i] == 0)
			ft_error_exit("error");
		i++;
	}
	if (ft_strlen(buf) != 20)
		ft_error_exit("error");
	while (i < 26)
		items[i++] = 0;
	return (items);
}
