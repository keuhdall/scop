/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 18:46:05 by lmarques          #+#    #+#             */
/*   Updated: 2018/05/01 19:28:40 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

void	handle_keyboard_input(t_scop *sc)
{
	if (glfwGetKey(sc->win, GLFW_KEY_UP) == GLFW_PRESS)
	{
		sc->cam.cam_pos = sum3(sc->cam.cam_pos, prod3_c(sc->cam.cam_dir,
				sc->time.delta * sc->cam.move_speed));
	}
	if (glfwGetKey(sc->win, GLFW_KEY_DOWN) == GLFW_PRESS)
	{
		sc->cam.cam_pos = diff3(sc->cam.cam_pos, prod3_c(sc->cam.cam_dir,
				sc->time.delta * sc->cam.move_speed));
	}
	if (glfwGetKey(sc->win, GLFW_KEY_RIGHT) == GLFW_PRESS)
	{
		sc->cam.cam_pos = sum3(sc->cam.cam_pos, prod3_c(sc->cam.right_vec,
				sc->time.delta * sc->cam.move_speed));
	}
	if (glfwGetKey(sc->win, GLFW_KEY_LEFT) == GLFW_PRESS)
	{
		sc->cam.cam_pos = diff3(sc->cam.cam_pos, prod3_c(sc->cam.right_vec,
				sc->time.delta * sc->cam.move_speed));
	}
}

void	refresh_mouse_view(t_scop *sc)
{
	glfwGetCursorPos(sc->win, &sc->cam.mouse_pos.x, &sc->cam.mouse_pos.y);
	glfwSetCursorPos(sc->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	sc->cam.h_angle += sc->cam.mouse_speed * sc->time.delta *
		(float)(WIN_WIDTH / 2 - sc->cam.mouse_pos.x);
	sc->cam.v_angle += sc->cam.mouse_speed * sc->time.delta *
		(float)(WIN_HEIGHT / 2 - sc->cam.mouse_pos.y);
	sc->cam.cam_dir = (t_vec3){
		cos(sc->cam.v_angle) * sin(sc->cam.h_angle),
		sin(sc->cam.v_angle),
		cos(sc->cam.v_angle) * cos(sc->cam.h_angle)
	};
	sc->cam.right_vec = (t_vec3){
		sin(sc->cam.h_angle - 3.14f / 2.0f),
		0,
		cos(sc->cam.h_angle - 3.14f / 2.0f)
	};
	sc->cam.up_vec = cross3(sc->cam.right_vec, sc->cam.cam_dir);
}
