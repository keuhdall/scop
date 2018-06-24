/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 19:04:25 by lmarques          #+#    #+#             */
/*   Updated: 2018/06/24 21:19:20 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

void	read_header(t_scop *sc, int fd)
{
	int		height;
	char	header[54];
	int		width;

	read(fd, header, 54);
	width = *(int *)&header[18];
	height = *(int *)&header[22];
}

void	parse_bmp(char *name, t_scop *sc)
{
	int		fd;
	int		ret;
	char	*line;

	fd = open(name, O_RDONLY);
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
			puterr(ERR_OPEN_FILE);
		free(line);
	}
	free(line);
	close(fd);
}
