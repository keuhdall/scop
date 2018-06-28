/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 19:04:25 by lmarques          #+#    #+#             */
/*   Updated: 2018/06/28 03:47:20 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

void			read_header(t_scop *sc, int fd)
{
	int		height;
	char	header[54];
	int		width;

	read(fd, header, 54);
	sc->bmp.width = *(int *)&header[18];
	sc->bmp.height = *(int *)&header[22];
	sc->bmp.size = 3 * width * height;
}

unsigned char	get_bmp_pixel(t_scop *sc, int width_index, int height_index)
{
	if (!sc->bmp.data)
		return (0);
	return (sc->bmp.data[3 * (width_index * sc->bmp.width * height_index)]);
}

void			parse_bmp(char *name, t_scop *sc)
{
	int				count;
	int				fd;
	unsigned char	tmp;

	count = 0;
	fd = open(name, O_RDONLY);
	read_header(sc, fd);
	read(fd, &sc->bmp.data, sc->bmp.size);
	while (count < sc->bmp.size)
	{
		tmp = sc->bmp.data[count];
		sc->bmp.data[count] = sc->bmp.data[count + 2];
		sc->bmp.data[count + 2] = tmp;
		count += 3;
	}
	close(fd);
}
