/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:05:10 by lmarques          #+#    #+#             */
/*   Updated: 2018/11/19 16:31:44 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

void	parse_v(char *line, t_scop *sc)
{
	char	**a;
	t_vec3	v3;

	a = ft_strsplit(line, ' ');
	if (get_array_size(a) != 4)
		puterr(ERR_BAD_FORMAT);
	v3.x = atof(a[1]);
	v3.y = atof(a[2]);
	v3.z = atof(a[3]);
	free_array(a);
	sc->tmp_v_size++;
	sc->tmp_v_array = realloc(sc->tmp_v_array, sizeof(t_vec3) *
		sc->tmp_v_size);
	sc->tmp_v_array[sc->tmp_v_size - 1] = v3;
}

void	parse_vt(char *line, t_scop *sc)
{
	char	**a;
	t_vec2	v2;

	a = ft_strsplit(line, ' ');
	if (get_array_size(a) != 3)
		puterr(ERR_BAD_FORMAT);
	v2.x = atof(a[1]);
	v2.y = atof(a[2]);
	free_array(a);
	sc->tmp_vt_size++;
	sc->tmp_vt_array = realloc(sc->tmp_vt_array, sizeof(t_vec2) *
		sc->tmp_vt_size);
	sc->tmp_vt_array[sc->tmp_vt_size - 1] = v2;
}

void	parse_vn(char *line, t_scop *sc)
{
	char	**a;
	t_vec3	v3;

	a = ft_strsplit(line, ' ');
	if (get_array_size(a) != 4)
		puterr(ERR_BAD_FORMAT);
	v3.x = atof(a[1]);
	v3.y = atof(a[2]);
	v3.z = atof(a[3]);
	free_array(a);
	sc->tmp_vn_size++;
	sc->tmp_vn_array = realloc(sc->tmp_vn_array, sizeof(t_vec3) *
		sc->tmp_vn_size);
	sc->tmp_vn_array[sc->tmp_vn_size - 1] = v3;
}

void	parse_f(char *line, t_scop *sc)
{
	int		count;
	char	**a;
	t_face	f;

	count = 0;
	a = ft_strsplit(line, ' ');
	ft_bzero(&f, sizeof(f));
	if (get_array_size(a) < 4)
		puterr(ERR_BAD_FORMAT);
	while (a[++count])
	{
		fill_f(a[count], &f);
	}
	free_array(a);
	sc->f_size++;
	sc->f_array = realloc(sc->f_array, sizeof(t_face) * sc->f_size);
	sc->f_array[sc->f_size - 1] = f;
}
