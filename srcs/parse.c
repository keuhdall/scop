/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:05:10 by lmarques          #+#    #+#             */
/*   Updated: 2018/03/17 13:22:08 by lmarques         ###   ########.fr       */
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
	sc->v_size++;
	sc->v_array = ft_realloc(sc->v_array, sizeof(t_vec3) * sc->v_size);
	sc->v_array[sc->v_size - 1] = v3;
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
	sc->vt_size++;
	sc->vt_array = ft_realloc(sc->vt_array, sizeof(t_vec2) * sc->vt_size);
	sc->vt_array[sc->vt_size - 1] = v2;
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
	sc->vn_size++;
	sc->vn_array = ft_realloc(sc->vn_array, sizeof(t_vec3) * sc->vn_size);
	sc->vn_array[sc->vn_size - 1] = v3;
}

void	fill_f(char *s, t_face *f)
{
	char	**a;

	a = ft_strsplit(s, '/');
	f->v_size++;
	f->vt_size++;
	f->vn_size++;
	f->v = ft_realloc(f->v, sizeof(int) * f->v_size);
	f->vt = ft_realloc(f->vt, sizeof(int) * f->vt_size);
	f->vn = ft_realloc(f->vn, sizeof(int) * f->vn_size);
	if (!count_char(s, '/'))
	{
		f->v[f->v_size - 1] = atoi(s);
		f->vt[f->vt_size - 1] = 0;
		f->vn[f->vn_size - 1] = 0;
	}
	else if (get_array_size(a) >= 3)
	{
		f->v[f->v_size - 1] = atoi(a[0]);
		f->vt[f->vt_size - 1] = atoi(a[1]);
		f->vn[f->vn_size - 1] = atoi(a[2]);
	}
	else
		puterr(ERR_BAD_FORMAT);
	free_array(a);
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
		fill_f(a[count], &f);
	free_array(a);
	sc->f_size++;
	sc->f_array = ft_realloc(sc->f_array, sizeof(t_face) * sc->f_size);
	sc->f_array[sc->f_size - 1] = f;
}
