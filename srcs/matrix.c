/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 16:02:22 by lmarques          #+#    #+#             */
/*   Updated: 2018/03/18 17:35:45 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

t_vec4	*new_matrix(void)
{
	t_vec4	*mat;

	if (!(mat = (t_vec4 *)malloc(sizeof(t_vec4) * 4)))
		return (NULL);
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

	m = ft_memalloc(sizeof(t_vec4) * 4);
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

float	dot(t_vec3 a, t_vec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}


t_vec3	normalize(t_vec3 v)
{
	float	len;
	t_vec3	normalized;

	len = sqrt(dot(v, v));
	normalized = (quo3_c(v, len));
	return (normalized);
}

t_vec4	*lookat(t_vec3 pos, t_vec3 target, t_vec3 upvec)
{
	t_vec3	v[3];
	t_vec4	*mat;

	v[0] = normalize(diff3(target, pos));
	v[1] = normalize(upvec);
	v[2] = normalize(cross3(v[0], v[1]));
	mat = new_matrix();
	mat[0].x = v[2].x;
	mat[1].x = v[2].y;
	mat[2].x = v[2].z;
	mat[0].y = v[1].x;
	mat[1].y = v[1].y;
	mat[2].y = v[1].z;
	mat[0].z = -v[0].x;
	mat[1].z = -v[0].y;
	mat[2].z = -v[0].z;
	mat[3].x = -(dot(v[2], pos));
	mat[3].y = -(dot(v[1], pos));
	mat[3].z =  dot(v[0], pos);
	return (mat);
}
