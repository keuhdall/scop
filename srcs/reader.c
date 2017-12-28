/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:05:10 by lmarques          #+#    #+#             */
/*   Updated: 2017/12/17 18:17:51 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

void	read_file(char *name, t_scop *s)
{
	int		fd;
	int		ret;
	char	*line;

	check_fd(fd = open(name, O_RDONLY));
	while ((ret = get_next_line(fd, &line)))
	{
		if (!strncmp(line, "v", 1))
			parse_v(line, s);
		else if (!strcmp(line, "vt"))
			parse_vt(line, s);
		else if (!strcmp(line, "vn"))
			parse_vn(line, s);
		free(line);
	}
	free(line);
}
