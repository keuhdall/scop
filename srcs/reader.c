/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:05:10 by lmarques          #+#    #+#             */
/*   Updated: 2018/11/27 16:59:40 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

void	get_line_type(char *line, t_scop *sc)
{
	printf("current line is : %s\n", line);
	if (!strncmp(line, "vt", 2))
		parse_vt(line, sc);
	else if (!strncmp(line, "vn", 2))
		parse_vn(line, sc);
	else if (!strncmp(line, "v", 1))
		parse_v(line, sc);
	else if (!strncmp(line, "f", 1))
		parse_f(line, sc);
}

void	read_file(char *name, t_scop *sc, char *tex)
{
	int		fd;
	int		ret;
	char	*line;

	fd = open(name, O_RDONLY);
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
			puterr(ERR_OPEN_FILE);
		get_line_type(line, sc);
		free(line);
	}
	free(line);
	close(fd);
	if (tex)
		parse_bmp(tex, sc);
}
