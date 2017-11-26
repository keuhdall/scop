/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:05:10 by lmarques          #+#    #+#             */
/*   Updated: 2017/11/23 22:24:47 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

void	read_file(char *name)
{
	int		ret;
	int		fd;
	char	*line;

	fd = open(name, O_RDONLY);
	check_fd(fd);
	while ((ret = get_next_line(fd, &line)))
	{
		free(line);
	}
	free(line);
}
