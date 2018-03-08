/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:05:10 by lmarques          #+#    #+#             */
/*   Updated: 2018/03/08 07:56:47 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

void	read_file(char *name, t_scop *sc)
{
	int		fd;
	int		ret;
	char	*line;

	check_fd(fd = open(name, O_RDONLY));
	while ((ret = get_next_line(fd, &line)))
	{
		if (!strncmp(line, "v", 1))
			parse_v(line, sc);
		else if (!strncmp(line, "f", 1))
			parse_f(line, sc);
		free(line);
	}
	free(line);
}
