/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 16:02:22 by lmarques          #+#    #+#             */
/*   Updated: 2018/03/19 19:13:01 by lmarques         ###   ########.fr       */
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

t_vec4	*lookat(t_vec3 eye, t_vec3 target, t_vec3 up)
{
	t_vec3	v[3];
	t_vec4	*orientation;
	t_vec4	*translation;
	t_vec4	*res;

	v[0] = normalize(diff3(eye, target));    // The "forward" vector.
	v[1] = normalize(cross3(up, v[0]));// The "right" vector.
	v[2] = cross3(v[0], v[1]);     // The "up" vector.
	orientation = new_matrix();
	translation = new_matrix();
	res = new_matrix();
	orientation[0].x = v[1].x;
	orientation[0].y = v[2].x;
	orientation[0].z = v[0].x;
	orientation[1].x = v[1].y;
	orientation[1].y = v[2].y;
	orientation[1].z = v[0].y;
	orientation[2].x = v[1].z;
	orientation[2].y = v[2].z;
	orientation[2].z = v[0].z;
	orientation[3].w = 1;
	translation[0].x = 1;
	translation[1].y = 1;
	translation[2].z = 1;
	translation[3].x = -eye.x;
	translation[3].y = -eye.y;
	translation[3].z = -eye.z;
	res = mat_prod(orientation, translation);
	free(orientation);
	free(translation);
	return (res);
}
