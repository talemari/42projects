/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_bmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 11:08:45 by talemari          #+#    #+#             */
/*   Updated: 2017/06/09 09:57:54 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.cuh"
#include "gui.h"
#include "bmp_infos.h"

/*
**	Writes the header at the very beginning of the file
**	Needs the structure t_bmp_header, which contains all the file informations
**	@param fd: The file descriptor of the opened file
**	@param width, height: The pixelmap dimensions
*/

void		write_header(int fd, int width, int height)
{
	t_bmp_header	*header;

	if (!(header = (t_bmp_header *)malloc(sizeof(t_bmp_header))))
		ft_error_exit("Malloc error");
	header->signature = 0x4D42;
	header->file_size = width * height * sizeof(t_rgb) * sizeof(header);
	header->reserv_1 = 0;
	header->reserv_2 = 0;
	header->offset = 54;
	header->chunk = 40;
	header->width = width;
	header->height = -height;
	header->plans = 1;
	header->nb_bits = 24;
	header->compression = 0;
	header->x_size = 0;
	header->xpm = 0;
	header->ypm = 0;
	header->clr_nbr = 0;
	header->clr_imprt = 0;
	write(fd, ((BYTE *)header) + 2, 54);
	free(header);
}

/*
**	Exports a pixelmap to a bmp file
**	@param: data is a t_th_export struct, that contains the datas to write,
**		the fd, etc.
*/

void		*export_image(void *data)
{
	int			fd;
	int			i;
	t_pt2		res;
	t_th_export	*th_export;

	th_export = (t_th_export*)data;
	res = th_export->g->r->scene->res;
	if (!(fd = open(th_export->filename, O_WRONLY | O_CREAT | O_TRUNC, 0600)))
		return (NULL);
	write_header(fd, res.x, res.y);
	i = -1;
	while (++i < res.x * res.y)
	{
		write(fd, &th_export->g->r->d_pixel_map[i].b, sizeof(BYTE));
		write(fd, &th_export->g->r->d_pixel_map[i].g, sizeof(BYTE));
		write(fd, &th_export->g->r->d_pixel_map[i].r, sizeof(BYTE));
		if (i % res.x == 0)
			th_export->progress = (double)i / (res.x * res.y) + 0.1;
	}
	close(fd);
	return (NULL);
}
