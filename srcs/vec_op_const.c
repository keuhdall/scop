/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 16:09:52 by lmarques          #+#    #+#             */
/*   Updated: 2018/03/24 00:05:13 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

t_vec3	sum3_c(t_vec3 a, float b)
{
	return ((t_vec3){a.x + b, a.y + b, a.z + b});
}

t_vec3	diff3_c(t_vec3 a, float b)
{
	return ((t_vec3){a.x - b, a.y - b, a.z - b});
}

t_vec3	prod3_c(t_vec3 a, float b)
{
	return ((t_vec3){a.x * b, a.y * b, a.z * b});
}

t_vec3	quo3_c(t_vec3 a, float b)
{
	return ((t_vec3){a.x / b, a.y / b, a.z / b});
}
