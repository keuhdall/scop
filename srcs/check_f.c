/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:35:44 by lmarques          #+#    #+#             */
/*   Updated: 2018/11/19 17:14:07 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

void	check_index(t_scop *sc, int index, int f_index)
{
	int	count;

	count = 0;
	if (index == V_INDEX)
	{
		while (count < sc->f_array[f_index].v[count])
		{
			if (sc->f_array[f_index].v[count] >= sc->v_size)
				puterr(ERR_BAD_FORMAT);
			count++;
		}
	}
	else if (index == VT_INDEX)
	{
		while (count < sc->f_array[f_index].vt[count])
		{
			if (sc->f_array[f_index].vt[count] >= sc->vt_size)
				puterr(ERR_BAD_FORMAT);
			count++;
		}
	}
	else if (index == VN_INDEX)
	{
		while (count < sc->f_array[f_index].vn[count])
		{
			if (sc->f_array[f_index].vn[count] >= sc->vn_size)
				puterr(ERR_BAD_FORMAT);
			count++;
		}
	}
}

void	check_f(t_scop *sc)
{
	int	count;

	count = -1;
	while (sc->f_array + (++count))
	{
		check_index(sc, V_INDEX, count);
		check_index(sc, VT_INDEX, count);
		check_index(sc, VN_INDEX, count);
	}
}
