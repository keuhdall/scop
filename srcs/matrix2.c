/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:34:46 by lmarques          #+#    #+#             */
/*   Updated: 2018/03/21 15:55:07 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

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

t_vec4		*lookat(t_vec3 eye, t_vec3 target, t_vec3 up)
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
	set_orientation(orientation, v);
	set_translation(translation, eye);
	res = mat_prod(orientation, translation);
	free(orientation);
	free(translation);
	return (res);
}
