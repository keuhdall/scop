/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 16:02:22 by lmarques          #+#    #+#             */
/*   Updated: 2018/03/21 15:54:30 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

t_vec4	*new_matrix(void)
{
	t_vec4	*mat;

	if (!(mat = (t_vec4 *)malloc(sizeof(t_vec4) * 4)))
		puterr(ERR_MALLOC_FAILED);
	ft_bzero(mat, sizeof(t_vec4) * 4);
	return (mat);
}

void	transform(t_vec4 *m, t_vec4 v)
{
	m[0].x *= v.x;
	m[0].y *= v.y;
	m[0].z *= v.z;
	m[0].w *= v.w;
	m[1].x *= v.x;
	m[1].y *= v.y;
	m[1].z *= v.z;
	m[1].w *= v.w;
	m[2].x *= v.x;
	m[2].y *= v.y;
	m[2].z *= v.z;
	m[2].w *= v.w;
	m[3].x *= v.x;
	m[3].y *= v.y;
	m[3].z *= v.z;
	m[3].w *= v.w;
}

t_vec4	*translate(t_vec4 v, t_vec3 pos)
{
	t_vec4	*m;

	m = new_matrix();
	m[0].x = 1;
	m[0].w = pos.x;
	m[1].y = 1;
	m[1].w = pos.y;
	m[2].z = 1;
	m[2].w = pos.z;
	m[3].w = 1;
	transform(m, v);
	return (m);
}

t_vec4	scale(t_vec4 v, t_vec3 pos)
{
	v.x *= pos.x;
	v.y *= pos.y;
	v.z *= pos.z;
	return (v);
}

void	perspective(t_vec4 *m, float f[4])
{
	float	angle_half;

	angle_half = tan(f[0] / 2.0f);
	m[0].x = (1.0f / (f[1] * angle_half));
	m[1].y = (1.0f / angle_half);
	m[2].z = (-(f[3] + f[2]) / (f[3] - f[2]));
	m[3].z = -1.0f;
	m[2].w = (-(2.0f * f[3] * f[2]) / (f[3] - f[2]));
}
