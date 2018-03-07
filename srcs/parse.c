/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:05:10 by lmarques          #+#    #+#             */
/*   Updated: 2018/03/07 17:20:14 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

void	parse_v(char *line, t_scop *s)
{
	int		count;
	char	**a;
	t_vec3	vert;

	count = -1;
	a = ft_strsplit(line, ' ');
	if (get_array_size(a) != 4)
	{
		dprintf(2, "Error : bad format in given file\n");
		exit(1);
	}
	vert.x = atof(a[1]);
	vert.y = atof(a[2]);
	vert.z = atof(a[3]);
	ft_lst_push_back(&s->tmp_list, ft_lstnew(&vert, sizeof(vert)));
	free_array(a);
	//MIGHT CHANGE
}

void	parse_vt(char *line, t_scop *s)
{
	char	**a;
	t_vec2	uv;

	a = ft_strsplit(line, ' ');
	if (get_array_size(a) != 3)
	{
		dprintf(2, "Error : bad format in given file\n");
		exit(1);
	}
	uv.x = atof(a[1]);
	uv.y = atof(a[2]);
	ft_lst_push_back(&s->tmp_list, ft_lstnew(&uv, sizeof(uv)));
	free_array(a);
	//MIGHT CHANGE
}

void	parse_vn(char *line, t_scop *s)
{
	char	**a;
	t_vec3	nl;

	a = ft_strsplit(line, ' ');
	if (get_array_size(a) != 4)
	{
		dprintf(2, "Error : bad format in given file\n");
		exit(1);
	}
	nl.x = atof(a[1]);
	nl.y = atof(a[2]);
	nl.z = atof(a[3]);
	ft_lst_push_back(&s->tmp_list, ft_lstnew(&nl, sizeof(nl)));
	free_array(a);
	//MIGHT CHANGE
}
/*
void	parse_n(char *line, t_scop *s)
{
	t_vec3	v[3];
	int		ret;

	if ((ret = fscanf(file, "%f/%f/%f %f/%f/%f %f/%f/%f\n",
		&v[0].x, &v[0].y, &v[0].z,
		&v[1].x, &v[1].y, &v[1].z,
		&v[2].x, &v[2].y, &v[2].z) != 9))
	{
		fprintf(stderr, "Error in file format\n");
		exit(1);
	}
	push_scop_lst(&s->tmp_list, new_scop_lst(F, &v));
	//MIGHT CHANGE
}
*/
