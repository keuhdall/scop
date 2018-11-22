/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:35:44 by lmarques          #+#    #+#             */
/*   Updated: 2018/11/20 15:58:45 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"



void	check_index(void *array, int array_size, int max_size)
{
	int	count;

	count = -1;
	while (++count < array_size)
	{
		if (((int *)array)[count] > max_size)
			puterr(ERR_BAD_FORMAT);
	}
}

void	check_f(t_scop *sc)
{
	int	count;

	count = -1;
	while (++count < sc->f_size)
	{
		check_index(sc->f_array[count].v, sc->f_array[count].v_size,
			sc->tmp_v_size);
		check_index(sc->f_array[count].vt, sc->f_array[count].vt_size,
			sc->tmp_vt_size);
		check_index(sc->f_array[count].vn, sc->f_array[count].vn_size,
			sc->tmp_vn_size);
	}
}
