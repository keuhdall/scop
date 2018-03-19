/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 19:27:36 by lmarques          #+#    #+#             */
/*   Updated: 2018/03/19 19:07:49 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

t_vec4	*mat_sum(t_vec4 *a, t_vec4 *b)
{
	int		count;
	t_vec4	*mat;

	count = -1;
	mat = new_matrix();
	while (++count < 4)
	{
		mat[count].x = a[count].x + b[count].x;
		mat[count].y = a[count].y + b[count].y;
		mat[count].z = a[count].z + b[count].z;
		mat[count].w = a[count].w + b[count].w;
	}
	return (mat);
}

t_vec4	*mat_diff(t_vec4 *a, t_vec4 *b)
{
	int		count;
	t_vec4	*mat;

	count = -1;
	mat = new_matrix();
	while (++count < 4)
	{
		mat[count].x = a[count].x - b[count].x;
		mat[count].y = a[count].y - b[count].y;
		mat[count].z = a[count].z - b[count].z;
		mat[count].w = a[count].w - b[count].w;
	}
	return (mat);
}

/*
	m[0].x = a[0].x * b[0].x + a[0].y * b[1].x + a[0].z * b[2].x + a[0].w * b[3].x;
	m[0].y = a[0].x * b[0].y + a[0].y * b[1].y + a[0].z * b[2].y + a[0].w * b[3].y;
	m[0].z = a[0].x * b[0].z + a[0].y * b[1].z + a[0].z * b[2].z + a[0].w * b[3].z;
	m[0].w = a[0].x * b[0].w + a[0].y * b[1].w + a[0].z * b[2].w + a[0].w * b[3].w;
	m[1].x = a[1].x * b[0].x + a[1].y * b[1].x + a[1].z * b[2].x + a[1].w * b[3].x;
	m[1].y = a[1].x * b[0].y + a[1].y * b[1].y + a[1].z * b[2].y + a[1].w * b[3].y;
	m[1].z = a[1].x * b[0].z + a[1].y * b[1].z + a[1].z * b[2].z + a[1].w * b[3].z;
	m[1].w = a[1].x * b[0].w + a[1].y * b[1].w + a[1].z * b[2].w + a[1].w * b[3].w;
	m[2].x = a[2].x * b[0].x + a[2].y * b[1].x + a[2].z * b[2].x + a[2].w * b[3].x;
	m[2].y = a[2].x * b[0].y + a[2].y * b[1].y + a[2].z * b[2].y + a[2].w * b[3].y;
	m[2].z = a[2].x * b[0].z + a[2].y * b[1].z + a[2].z * b[2].z + a[2].w * b[3].z;
	m[2].w = a[2].x * b[0].w + a[2].y * b[1].w + a[2].z * b[2].w + a[2].w * b[3].w;
	m[3].x = a[3].x * b[0].x + a[3].y * b[1].x + a[3].z * b[2].x + a[3].w * b[3].x;
	m[3].y = a[3].x * b[0].y + a[3].y * b[1].y + a[3].z * b[2].y + a[3].w * b[3].y;
	m[3].z = a[3].x * b[0].z + a[3].y * b[1].z + a[3].z * b[2].z + a[3].w * b[3].z;
	m[3].w = a[3].x * b[0].w + a[3].y * b[1].w + a[3].z * b[2].w + a[3].w * b[3].w;
*/
t_vec4	*mat_prod(t_vec4 *a, t_vec4 *b)
{
	int		count;
	t_vec4	*mat;

	count = -1;
	mat = new_matrix();
	while (++count < 4)
	{
		mat[count].x = a[count].x * b[0].x + a[count].y * b[1].x +
			a[count].z * b[2].x + a[count].w * b[3].x;
		mat[count].y = a[count].x * b[0].y + a[count].y * b[1].y +
			a[count].z * b[2].y + a[count].w * b[3].y;
		mat[count].z = a[count].x * b[0].z + a[count].y * b[1].z +
			a[count].z * b[2].z + a[count].w * b[3].z;
		mat[count].w = a[count].x * b[0].w + a[count].y * b[1].w +
			a[count].z * b[2].w + a[count].w * b[3].w;
	}
	return (mat);
}

t_vec4	*mat_quo(t_vec4 *a, t_vec4 *b)
{
	int		count;
	t_vec4	*mat;

	count = -1;
	mat = new_matrix();
	while (++count < 4)
	{
		mat[count].x = a[count].x / b[0].x + a[count].y / b[1].x +
			a[count].z / b[2].x + a[count].w / b[3].x;
		mat[count].y = a[count].x / b[0].y + a[count].y / b[1].y +
			a[count].z / b[2].y + a[count].w / b[3].y;
		mat[count].z = a[count].x / b[0].z + a[count].y / b[1].z +
			a[count].z / b[2].z + a[count].w / b[3].z;
		mat[count].w = a[count].x / b[0].w + a[count].y / b[1].w +
			a[count].z / b[2].w + a[count].w / b[3].w;
	}
	return (mat);
}

