/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 16:02:22 by lmarques          #+#    #+#             */
/*   Updated: 2018/03/17 18:16:40 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

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
