/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:05:10 by lmarques          #+#    #+#             */
/*   Updated: 2018/03/14 03:56:38 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

void	parse_v(char *line, t_scop *sc)
{
	char	**a;
	t_vec3	*vert;

	if (!(vert = (t_vec3 *)malloc(sizeof(t_vec3))))
		puterr(ERR_MALLOC_FAILED);
	a = ft_strsplit(line, ' ');
	if (get_array_size(a) != 4)
		puterr(ERR_BAD_FORMAT);
	vert->x = atof(a[1]);
	vert->y = atof(a[2]);
	vert->z = atof(a[3]);
	sc->v_size++;
	sc->v_array = ft_realloc(sc->v_array, sizeof(t_vec3) * sc->v_size);
	sc->v_array[sc->v_size - 1] = vert;
}

int		get_f_array_size(t_scop *sc)
{
	int	count;
	int	size;

	count = -1;
	size = 0;
	while (++count < sc->f_size)
		size += sizeof(sc->f_array[count]);
	return (size);
}

void	parse_f(char *line, t_scop *sc)
{
	char	**a;
	t_vec3	*v3;
	t_vec4	*v4;

	a = ft_strsplit(line, ' ');
	if (get_array_size(a) == 4)
	{
		if (!(v3 = (t_vec3 *)malloc(sizeof(t_vec3))))
			puterr(ERR_MALLOC_FAILED);
		v3->x = atof(a[1]);
		v3->y = atof(a[2]);
		v3->z = atof(a[3]);
		sc->f_array = ft_realloc(sc->f_array, get_f_array_size(sc) + sizeof(t_vec3));
		sc->f_array[sc->f_size++] = v3;
	}
	else if (get_array_size(a) == 5)
	{
		if (!(v4 = (t_vec4 *)malloc(sizeof(t_vec4))))
			puterr(ERR_MALLOC_FAILED);
		v4->x = atof(a[1]);
		v4->y = atof(a[2]);
		v4->z = atof(a[3]);
		v4->w = atof(a[4]);
		sc->f_array = ft_realloc(sc->f_array, get_f_array_size(sc) + sizeof(t_vec4));
		sc->f_array[sc->f_size++] = v4;
	}
	else
		puterr(ERR_BAD_FORMAT);
}
