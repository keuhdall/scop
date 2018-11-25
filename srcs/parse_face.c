/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_face.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:17:29 by lmarques          #+#    #+#             */
/*   Updated: 2018/11/20 18:16:27 by lmarques         ###   ########.fr       */
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
	static int	counts[3] = {0, 0, 0};
	int			count;

	count = -1;
	sc->v_size = get_v_size(sc);
	sc->vt_size = get_vt_size(sc);
	sc->vn_size = get_vn_size(sc);
	if (!(sc->v_array = (t_vec3 *)malloc(sizeof(t_vec3) * sc->v_size)) ||
		!(sc->vt_array = (t_vec2 *)malloc(sizeof(t_vec2) * sc->vt_size)) ||
		!(sc->vn_array = (t_vec3 *)malloc(sizeof(t_vec3) * sc->vn_size)))
		puterr(ERR_MALLOC_FAILED);
	printf("v_size : %d ; vt_size : %d ; vn_size : %d\n", sc->v_size, sc->vt_size, sc->vn_size);
	while (++count < sc->f_size)
	{
		printf("count is : %d ; array size is : %d\n", count, sc->f_array[count].v_size);
		if (sc->f_array[count].v_size <= 3)
			push_triangle(sc, sc->f_array[count], &counts);
		else
			push_square(sc, sc->f_array[count], &counts);
	}
}
