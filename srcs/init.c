/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:05:10 by lmarques          #+#    #+#             */
/*   Updated: 2018/03/23 19:26:50 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

void	init_glfw(void)
{
	if (!glfwInit())
		puterr(ERR_INIT_GLFW);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void	init_glew(void)
{
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
		puterr(ERR_INIT_GLEW);
}

void	init_window(t_scop *sc)
{
	sc->win = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, "Hello Triangle",
			NULL, NULL);
	if (!sc->win)
		puterr(ERR_OPEN_WIN);
	glfwMakeContextCurrent(sc->win);
	glfwWindowHint(GLFW_SAMPLES, 4);
}

void	init_matrix(t_scop *sc)
{
	t_vec4	*projection_m;
	t_vec4	*view_m;
	t_vec4	*model_m;
	float	f[4];

	projection_m = new_matrix();
	f[0] = degrees_to_rad(45.0f);
	f[1] = WIN_WIDTH / WIN_HEIGHT;
	f[2] = 0.1f;
	f[3] = 100.0f;
	perspective(projection_m, f);
	view_m = lookat(
			(t_vec3){4.0, 3.0, -3.0},
			(t_vec3){0.0, 0.0, 0.0},
			(t_vec3){0.0, 1.0, 0.0});
	model_m = new_identity_m();
	sc->mvp = mvp(model_m, view_m, projection_m);
	free(model_m);
	free(view_m);
	free(projection_m);
}

void	init(t_scop *sc)
{
	init_glfw();
	init_window(sc);
	init_glew();
	init_matrix(sc);
	sc->cam.cam_pos = (t_vec3){0.0f, 0.0f, 5.0f};
	sc->cam.move_speed = 3.0f;
	sc->cam.mouse_speed = 0.005f;
	sc->cam.h_angle = 3.14f;
	sc->cam.v_angle = 0.0f;
	sc->cam.fov = 45.0f;
	sc->cam.cam_dir = (t_vec3){
		cos(sc->cam.v_angle) * sin(sc->cam.h_angle),
		sin(sc->cam.v_angle),
		cos(sc->cam.v_angle) * cos(sc->cam.h_angle)
	};
}
