/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:34:46 by lmarques          #+#    #+#             */
/*   Updated: 2018/03/21 19:45:42 by lmarques         ###   ########.fr       */
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

static void	set_orientation(t_vec4 *orientation, t_vec3 v[3])
{
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
}

static void	set_translation(t_vec4 *translation, t_vec3 eye)
{
	translation[0].x = 1;
	translation[1].y = 1;
	translation[2].z = 1;
	translation[3].x = -eye.x;
	translation[3].y = -eye.y;
	translation[3].z = -eye.z;
}

/*
** v[0] = forward vector
** v[1] = right vector
** v[2] = up vector
*/

t_vec4		*lookat(t_vec3 eye, t_vec3 target, t_vec3 up)
{
	t_vec3	v[3];
	t_vec4	*orientation;
	t_vec4	*translation;
	t_vec4	*res;

	v[0] = normalize(diff3(eye, target));
	v[1] = normalize(cross3(up, v[0]));
	v[2] = cross3(v[0], v[1]);
	orientation = new_matrix();
	translation = new_matrix();
	set_orientation(orientation, v);
	set_translation(translation, eye);
	res = mat_prod(orientation, translation);
	free(orientation);
	free(translation);
	return (res);
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
