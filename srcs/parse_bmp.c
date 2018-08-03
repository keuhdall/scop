/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 19:04:25 by lmarques          #+#    #+#             */
/*   Updated: 2018/08/04 01:16:27 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

void			read_header(t_scop *sc, int fd)
{
	char	header[54];

	if (read(fd, header, 54) != 54 || header[0] != 'B' || header[1] != 'M')
		puterr(ERR_INVALID_BMP);
	sc->bmp.width = *(int *)&header[18];
	sc->bmp.height = *(int *)&header[22];
	sc->bmp.size = !*(int *)&header[0x22] ?
		3 * sc->bmp.width * sc->bmp.height : *(int *)&header[0x22];
}

char			*get_bmp_name(char *line)
{
	char	**a;
	char	*name;

	a = ft_strsplit(line, ' ');
	name = (!a[1] ? NULL : ft_strdup(a[1]));
	free_array(a);
	return (name);
}

void			parse_bmp(char *line, t_scop *sc)
{
	int				count;
	char			*name;
	int				fd;
	unsigned char	tmp;

	count = 0;
	if (!(name = get_bmp_name(line)))
		puterr(ERR_INVALID_BMP);
	printf("trying to open file : %s\n", name);
	fd = open(name, O_RDONLY);
	read_header(sc, fd);
	if (!(sc->bmp.data = (unsigned char *)malloc(sizeof(unsigned char) *
		sc->bmp.size)))
		puterr(ERR_MALLOC_FAILED);
	read(fd, sc->bmp.data, sc->bmp.size);
	while (count < sc->bmp.size)
	{
		tmp = sc->bmp.data[count];
		sc->bmp.data[count] = sc->bmp.data[count + 2];
		sc->bmp.data[count + 2] = tmp;
		count += 3;
	}
	close(fd);
}
