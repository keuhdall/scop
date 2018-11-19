/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_face.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:17:29 by lmarques          #+#    #+#             */
/*   Updated: 2018/11/19 16:51:42 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

void	fill_f1(char *s, t_face *f)
{
	f->v_size++;
	f->v = ft_realloc(f->v, sizeof(int) * f->v_size);
	f->v[f->v_size - 1] = atoi(s);
}

void	fill_f2(char **a, t_face *f)
{
	f->v_size++;
	f->vt_size++;
	f->v = ft_realloc(f->v, sizeof(int) * f->v_size);
	f->vt = ft_realloc(f->vt, sizeof(int) * f->vt_size);
	f->v[f->v_size - 1] = atoi(a[0]);
	f->vt[f->vt_size - 1] = atoi(a[1]);
}

void	fill_f3(char **a, t_face *f)
{
	f->v_size++;
	f->vt_size++;
	f->vn_size++;
	f->v = ft_realloc(f->v, sizeof(int) * f->v_size);
	f->vt = ft_realloc(f->vt, sizeof(int) * f->vt_size);
	f->vn = ft_realloc(f->vn, sizeof(int) * f->vn_size);
	f->v[f->v_size - 1] = atoi(a[0]);
	f->vt[f->vt_size - 1] = atoi(a[1]);
	f->vn[f->vn_size - 1] = atoi(a[2]);
}

void	fill_f(char *s, t_face *f)
{
	char	**a;

	a = ft_strsplit(s, '/');
	if (!count_char(s, '/'))
		fill_f1(s, f);
	else if (get_array_size(a) == 2)
		fill_f2(a, f);
	else if (get_array_size(a) == 3)
		fill_f3(a, f);
	else
		puterr(ERR_BAD_FORMAT);
	free_array(a);
}

void	resolve_f(t_scop *sc)
{
	int		count;
	t_vec3	*tmp_v;
	t_vec2	*tmp_vt;
	t_vec3	*tmp_vn;

	count = -1;
	if (!(tmp_v = (t_vec3 *)malloc(sizeof(t_vec3) * sc->v_size)))
		puterr(ERR_MALLOC_FAILED);
	if (!(tmp_vt = (t_vec2 *)malloc(sizeof(t_vec2) * sc->vt_size)))
		puterr(ERR_MALLOC_FAILED);
	if (!(tmp_vn = (t_vec3 *)malloc(sizeof(t_vec3) * sc->vn_size)))
		puterr(ERR_MALLOC_FAILED);
	memcpy(tmp_v, sc->v_array, sc->v_size);
	memcpy(tmp_vt, sc->vt_array, sc->vt_size);
	memcpy(tmp_vn, sc->vn_array, sc->vn_size);
	while (++count < sc->f_size)
	{
		sc->v_array[count] = tmp_v[sc->f_array[count].v[0]];
		sc->vt_array[count] = tmp_vt[sc->f_array[count].vt[0]];
		sc->vn_array[count] = tmp_vn[sc->f_array[count].vn[0]];
	}
	free(tmp_v);
	free(tmp_vt);
	free(tmp_vn);
}
