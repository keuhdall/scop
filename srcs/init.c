/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:05:10 by lmarques          #+#    #+#             */
/*   Updated: 2018/03/08 07:56:17 by lmarques         ###   ########.fr       */
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

void	init_window(t_scop *s)
{
	s->win = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, "Hello Triangle",
			NULL, NULL);
	if (!s->win)
		puterr(ERR_OPEN_WIN);
	glfwMakeContextCurrent(s->win);
}

void	init(t_scop *s)
{
	ft_bzero(s, sizeof(s));
	init_glfw();
	init_window(s);
	init_glew();
}
