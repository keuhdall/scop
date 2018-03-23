/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 19:27:36 by lmarques          #+#    #+#             */
/*   Updated: 2018/03/23 23:31:23 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

t_vec4	*mat_sum(t_vec4 *a, t_vec4 *b)
{
	t_vec4	*m;

	m = new_matrix();
	m[0] = (t_vec4){a[0].x + b[0].x, a[0].y + b[0].y,
		a[0].z + b[0].z, a[0].w + b[0].w};
	m[1] = (t_vec4){a[1].x + b[1].x, a[1].y + b[1].y,
		a[1].z + b[1].z, a[1].w + b[1].w};
	m[2] = (t_vec4){a[2].x + b[2].x, a[2].y + b[2].y,
		a[2].z + b[2].z, a[2].w + b[2].w};
	m[3] = (t_vec4){a[3].x + b[3].x, a[3].y + b[3].y,
		a[3].z + b[3].z, a[3].w + b[3].w};
	return (m);
}

t_vec4	*mat_diff(t_vec4 *a, t_vec4 *b)
{
	t_vec4	*m;

	m = new_matrix();
	m[0] = (t_vec4){a[0].x - b[0].x, a[0].y - b[0].y,
		a[0].z - b[0].z, a[0].w - b[0].w};
	m[1] = (t_vec4){a[1].x - b[1].x, a[1].y - b[1].y,
		a[1].z - b[1].z, a[1].w - b[1].w};
	m[2] = (t_vec4){a[2].x - b[2].x, a[2].y - b[2].y,
		a[2].z - b[2].z, a[2].w - b[2].w};
	m[3] = (t_vec4){a[3].x - b[3].x, a[3].y - b[3].y,
		a[3].z - b[3].z, a[3].w - b[3].w};
	return (m);
}

t_vec4	*mat_prod(t_vec4 *a, t_vec4 *b)
{
	t_vec4	*m;

	m = new_matrix();
	m[0] = (t_vec4){
		a[0].x * b[0].x + a[0].y * b[1].x + a[0].z * b[2].x + a[0].w * b[3].x,
		a[0].x * b[0].y + a[0].y * b[1].y + a[0].z * b[2].y + a[0].w * b[3].y,
		a[0].x * b[0].z + a[0].y * b[1].z + a[0].z * b[2].z + a[0].w * b[3].z,
		a[0].x * b[0].w + a[0].y * b[1].w + a[0].z * b[2].w + a[0].w * b[3].w};
	m[1] = (t_vec4){
		a[1].x * b[0].x + a[1].y * b[1].x + a[1].z * b[2].x + a[1].w * b[3].x,
		a[1].x * b[0].y + a[1].y * b[1].y + a[1].z * b[2].y + a[1].w * b[3].y,
		a[1].x * b[0].z + a[1].y * b[1].z + a[1].z * b[2].z + a[1].w * b[3].z,
		a[1].x * b[0].w + a[1].y * b[1].w + a[1].z * b[2].w + a[1].w * b[3].w};
	m[2] = (t_vec4){
		a[2].x * b[0].x + a[2].y * b[1].x + a[2].z * b[2].x + a[2].w * b[3].x,
		a[2].x * b[0].y + a[2].y * b[1].y + a[2].z * b[2].y + a[2].w * b[3].y,
		a[2].x * b[0].z + a[2].y * b[1].z + a[2].z * b[2].z + a[2].w * b[3].z,
		a[2].x * b[0].w + a[2].y * b[1].w + a[2].z * b[2].w + a[2].w * b[3].w};
	m[3] = (t_vec4){
		a[3].x * b[0].x + a[3].y * b[1].x + a[3].z * b[2].x + a[3].w * b[3].x,
		a[3].x * b[0].y + a[3].y * b[1].y + a[3].z * b[2].y + a[3].w * b[3].y,
		a[3].x * b[0].z + a[3].y * b[1].z + a[3].z * b[2].z + a[3].w * b[3].z,
		a[3].x * b[0].w + a[3].y * b[1].w + a[3].z * b[2].w + a[3].w * b[3].w};
	return (m);
}

t_vec4	*mat_quo(t_vec4 *a, t_vec4 *b)
{
	t_vec4	*m;

	m = new_matrix();
	m[0] = (t_vec4){
		a[0].x / b[0].x + a[0].y / b[1].x + a[0].z / b[2].x + a[0].w / b[3].x,
		a[0].x / b[0].y + a[0].y / b[1].y + a[0].z / b[2].y + a[0].w / b[3].y,
		a[0].x / b[0].z + a[0].y / b[1].z + a[0].z / b[2].z + a[0].w / b[3].z,
		a[0].x / b[0].w + a[0].y / b[1].w + a[0].z / b[2].w + a[0].w / b[3].w};
	m[1] = (t_vec4){
		a[1].x / b[0].x + a[1].y / b[1].x + a[1].z / b[2].x + a[1].w / b[3].x,
		a[1].x / b[0].y + a[1].y / b[1].y + a[1].z / b[2].y + a[1].w / b[3].y,
		a[1].x / b[0].z + a[1].y / b[1].z + a[1].z / b[2].z + a[1].w / b[3].z,
		a[1].x / b[0].w + a[1].y / b[1].w + a[1].z / b[2].w + a[1].w / b[3].w};
	m[2] = (t_vec4){
		a[2].x / b[0].x + a[2].y / b[1].x + a[2].z / b[2].x + a[2].w / b[3].x,
		a[2].x / b[0].y + a[2].y / b[1].y + a[2].z / b[2].y + a[2].w / b[3].y,
		a[2].x / b[0].z + a[2].y / b[1].z + a[2].z / b[2].z + a[2].w / b[3].z,
		a[2].x / b[0].w + a[2].y / b[1].w + a[2].z / b[2].w + a[2].w / b[3].w};
	m[3] = (t_vec4){
		a[3].x / b[0].x + a[3].y / b[1].x + a[3].z / b[2].x + a[3].w / b[3].x,
		a[3].x / b[0].y + a[3].y / b[1].y + a[3].z / b[2].y + a[3].w / b[3].y,
		a[3].x / b[0].z + a[3].y / b[1].z + a[3].z / b[2].z + a[3].w / b[3].z,
		a[3].x / b[0].w + a[3].y / b[1].w + a[3].z / b[2].w + a[3].w / b[3].w};
	return (m);
}
