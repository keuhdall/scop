/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   face_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:24:14 by lmarques          #+#    #+#             */
/*   Updated: 2018/11/20 16:30:53 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

int	get_v_size(t_scop *sc)
{
	int	count;
	int	count_v;

	count = -1;
	count_v = 0;
	while (++count < sc->f_size)
	{
		if (sc->f_array[count].v_size <= 3)
			count_v += sc->f_array[count].v_size;
		else
			count_v += 6;
	}
	return (count_v);
}

int	get_vt_size(t_scop *sc)
{
	int	count;
	int	count_vt;

	count = -1;
	count_vt = 0;
	while (++count < sc->f_size)
	{
		if (sc->f_array[count].vt_size <= 3)
			count_vt += sc->f_array[count].vt_size;
		else
			count_vt += 6;
	}
	return (count_vt);
}

int	get_vn_size(t_scop *sc)
{
	int	count;
	int	count_vn;

	count = -1;
	count_vn = 0;
	while (++count < sc->f_size)
	{
		if (sc->f_array[count].vn_size <= 3)
			count_vn += sc->f_array[count].vn_size;
		else
			count_vn += 6;
	}
	return (count_vn);
}
