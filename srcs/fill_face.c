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

void	resolve_arrays(t_scop *sc, t_face f)
{
	int			count[3];
	static int	count_v = 0;
	static int	count_vt = 0;
	static int	count_vn = 0;

	count[0] = -1;
	count[1] = -1;
	count[2] = -1;
	while (++count[0] < f.v_size)
	{
		sc->v_array[count_v] = sc->tmp_v_array[f.v[count[0]]];
		count_v++;
	}
	while (++count[1] < f.vt_size)
	{
		sc->vt_array[count_vt] = sc->tmp_vt_array[f.vt[count[1]]];
		count_vt++;
	}
	while (++count[2] < f.vn_size)
	{
		sc->vn_array[count_vn] = sc->tmp_vn_array[f.vn[count[2]]];
		count_vn++;
	}
}
