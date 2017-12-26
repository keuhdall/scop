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

void	reader_obj(char *name, t_scop *s)
{
	FILE *file;
	char	line[LINE_SIZE];
	int		res;

	file = fopen(name, "r");
	if (!file)
	{
		fprintf(stderr, "Failed to open the given model file");
		exit(1);
	}
	while (1)
	{
		res = fscanf(file, "%s", line);
		if (res == EOF)
			break ;
		if (!strcmp(line, "v"))
			parse_v(file, s);
		else if (!strcmp(line, "vt"))
			parse_vt(file, s);
		else if (!strcmp(line, "vn"))
			parse_vn(file, s);
	}
}
