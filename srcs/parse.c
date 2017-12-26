
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
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

void	parse_n(FILE *file, t_scop *s)
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
