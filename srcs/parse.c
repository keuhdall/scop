/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:05:10 by lmarques          #+#    #+#             */
/*   Updated: 2018/03/10 02:29:27 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

void	parse_v(char *line, t_scop *sc)
{
	char	**a;
	t_vec3	vert;
	t_obj	*tmp_obj;

	a = ft_strsplit(line, ' ');
	if (get_array_size(a) != 4)
		puterr(ERR_BAD_FORMAT);
	vert.x = atof(a[1]);
	vert.y = atof(a[2]);
	vert.z = atof(a[3]);
	tmp_obj = create_obj(V, &vert);
	ft_lst_push_back(&sc->tmp_list, ft_lstnew(tmp_obj, sizeof(tmp_obj)));
	free_array(a);
	//MIGHT CHANGE
}

void	parse_f(char *line, t_scop *sc)
{
	char	**a;
	t_obj	*tmp_obj;
	t_vec3	v3;
	t_vec4	v4;

	a = ft_strsplit(line, ' ');
	if (get_array_size(a) == 4)
	{
		v3.x = atof(a[1]);
		v3.y = atof(a[2]);
		v3.z = atof(a[3]);
		tmp_obj = create_obj(F, &v3);
		ft_lst_push_back(&sc->tmp_list, ft_lstnew(tmp_obj, sizeof(tmp_obj)));
	}
	else if (get_array_size(a) == 5)
	{
		v4.x = atof(a[1]);
		v4.y = atof(a[2]);
		v4.z = atof(a[3]);
		v4.w = atof(a[4]);
		tmp_obj = create_obj(F, &v4);
		ft_lst_push_back(&sc->tmp_list, ft_lstnew(tmp_obj, sizeof(tmp_obj)));
	}
	else
		puterr(ERR_BAD_FORMAT);
}
