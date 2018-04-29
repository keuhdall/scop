/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:34:46 by lmarques          #+#    #+#             */
/*   Updated: 2018/03/25 22:31:55 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

t_vec4		*new_identity_m(void)
{
	t_vec4	*m;

	m = new_matrix();
	m[0].x = 1.0f;
	m[1].y = 1.0f;
	m[2].z = 1.0f;
	m[3].w = 1.0f;
	return (m);
}

/*
** v[0] = forward vector -> Z
** v[1] = right vector   -> X
** v[2] = up vector      -> Y
*/

t_vec4		*lookat(t_vec3 eye, t_vec3 target, t_vec3 up)
{
	t_vec3	v[3];
	t_vec4	*m;

	v[0] = normalize(diff3(eye, target));
	v[1] = normalize(cross3(up, v[0]));
	v[2] = normalize(cross3(v[0], v[1]));
	m = new_matrix();
	m[0] = (t_vec4){v[1].x, v[1].y, v[1].z, -dot(v[1], eye)};
	m[1] = (t_vec4){v[2].x, v[2].y, v[2].z, -dot(v[2], eye)};
	m[2] = (t_vec4){v[0].x, v[0].y, v[0].z, -dot(v[0], eye)};
	m[3] = (t_vec4){0, 0, 0, 1};
	return (m);
}

t_vec4		*mvp(t_vec4 *model, t_vec4 *view, t_vec4 *projection)
{
	t_vec4	*tmp;
	t_vec4	*res;

	tmp = mat_prod(projection, view);
	res = mat_prod(tmp, model);
	free(tmp);
	return (res);
}
