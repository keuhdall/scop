/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_face.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:17:29 by lmarques          #+#    #+#             */
/*   Updated: 2018/11/20 18:16:27 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

void	push_triangle(t_scop *sc, t_face f, int	(*counts)[3])
{
	if (sc->v_size <= *counts[0] + 2 ||
		(sc->vt_size != 0 && sc->vt_size <= *counts[1] + 2) ||
		(sc->vt_size != 0 && sc->vn_size <= *counts[2] + 2))
	{
		printf("(1) Error occured for values :\nv_size : %d ; vt_size : %d ; vn_size : %d\ncounts[0] : %d ; counts[1] : %d ; counts[2] : %d\n", sc->v_size, sc->vt_size, sc->vn_size, *counts[0], *counts[1], *counts[2]);
		puterr(ERR_BAD_FORMAT);
	}
	sc->v_array[*counts[0]] = sc->tmp_v_array[f.v[0]];
	sc->v_array[*counts[0] + 1] = sc->tmp_v_array[f.v[1]];
	sc->v_array[*counts[0] + 2] = sc->tmp_v_array[f.v[2]];
	*counts[0] += 3;
	if (sc->vt_size)
	{
		sc->vt_array[*counts[1]] = sc->tmp_vt_array[f.v[0]];
		sc->vt_array[*counts[1] + 1] = sc->tmp_vt_array[f.v[1]];
		sc->vt_array[*counts[1] + 2] = sc->tmp_vt_array[f.v[2]];
		*counts[1] += 3;
	}
	if (sc->vn_size)
	{
		sc->vn_array[*counts[2]] = sc->tmp_vn_array[f.v[0]];
		sc->vn_array[*counts[2] + 1] = sc->tmp_vn_array[f.v[1]];
		sc->vn_array[*counts[2] + 2] = sc->tmp_vn_array[f.v[2]];
		*counts[2] += 3;
	}
}

void	push_square(t_scop *sc, t_face f, int (*counts)[3])
{
	if (sc->v_size <= *counts[0] + 5 ||
		(sc->vt_size != 0 && sc->vt_size <= *counts[1] + 5) ||
		(sc->vt_size != 0 && sc->vn_size <= *counts[2] + 5))
		{
		printf("(2) Error occured for values :\nv_size : %d ; vt_size : %d ; vn_size : %d\ncounts[0] : %d ; counts[1] : %d ; counts[2] : %d\n", sc->v_size, sc->vt_size, sc->vn_size, *counts[0], *counts[1], *counts[2]);
		puterr(ERR_BAD_FORMAT);
		}
	sc->v_array[*counts[0]] = sc->tmp_v_array[f.v[0]];
	sc->v_array[*counts[0] + 1] = sc->tmp_v_array[f.v[1]];
	sc->v_array[*counts[0] + 2] = sc->tmp_v_array[f.v[2]];
	sc->v_array[*counts[0] + 3] = sc->tmp_v_array[f.v[2]];
	sc->v_array[*counts[0] + 4] = sc->tmp_v_array[f.v[3]];
	sc->v_array[*counts[0] + 5] = sc->tmp_v_array[f.v[0]];
	*counts[0] += 6;
	if (sc->vt_size)
	{
	sc->vt_array[*counts[1]] = sc->tmp_vt_array[f.v[0]];
	sc->vt_array[*counts[1] + 1] = sc->tmp_vt_array[f.v[1]];
	sc->vt_array[*counts[1] + 2] = sc->tmp_vt_array[f.v[2]];
	sc->vt_array[*counts[1] + 3] = sc->tmp_vt_array[f.v[2]];
	sc->vt_array[*counts[1] + 4] = sc->tmp_vt_array[f.v[3]];
	sc->vt_array[*counts[1] + 5] = sc->tmp_vt_array[f.v[0]];
	*counts[1] += 6;
	}
	if (sc->vn_size)
	{
	sc->vn_array[*counts[2]] = sc->tmp_vn_array[f.v[0]];
	sc->vn_array[*counts[2] + 1] = sc->tmp_vn_array[f.v[1]];
	sc->vn_array[*counts[2] + 2] = sc->tmp_vn_array[f.v[2]];
	sc->vn_array[*counts[2] + 3] = sc->tmp_vn_array[f.v[2]];
	sc->vn_array[*counts[2] + 4] = sc->tmp_vn_array[f.v[3]];
	sc->vn_array[*counts[2] + 5] = sc->tmp_vn_array[f.v[0]];
	*counts[2] += 6;
	}
}
