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

void	parse_v(FILE *file, t_scop *s)
{
	t_vec3	vert;

	fscanf(file, "%f %f %f\n", &vert.x, &vert.y, &vert.z);
	push_scop_lst(&s->tmp_list, new_scop_lst(V, &vert));
	//MIGHT CHANGE
}

void	parse_vt(FILE *file, t_scop *s)
{
	t_vec2	uv;

	fscanf(file, "%f %f\n", &uv.x, &uv.y);
	push_scop_lst(&s->tmp_list, new_scop_lst(VT, &uv));
	//MIGHT CHANGE
}

void	parse_vn(FILE *file, t_scop *s)
{
	t_vec3	nl;

	fscanf(file, "%f %f %f\n", &nl.x, &nl.y, &nl.z);
	push_scop_lst(&s->tmp_list, new_scop_lst(VN, &nl));
	//MIGHT CHANGE
}

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
