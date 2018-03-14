/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:05:10 by lmarques          #+#    #+#             */
/*   Updated: 2018/03/14 04:09:29 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

void	read_array(t_scop *sc)
{
	int		count;
	void	*tmp;

	count = -1;
	while (++count < sc->v_size)
	{
		tmp = sc->v_array[count];
		printf("v : %f ; %f ; %f\n", ((t_vec3 *)tmp)->x, ((t_vec3 *)tmp)->y, ((t_vec3 *)tmp)->z);
	}
	count = -1;
	while (++count < sc->f_size)
	{
		tmp = sc->f_array[count];
		if (sizeof(sc->f_array[count]) == sizeof(t_vec3))
			printf("f : %f ; %f ; %f\n", ((t_vec3 *)tmp)->x, ((t_vec3 *)tmp)->y, ((t_vec3 *)tmp)->z);
		else if (sizeof(sc->f_array[count]) == sizeof(t_vec4))
			printf("f : %f ; %f ; %f ; %f\n", ((t_vec4 *)tmp)->x, ((t_vec4 *)tmp)->y, ((t_vec4 *)tmp)->z, ((t_vec4 *)tmp)->w);
		else
			printf("t_vec3 : %lu ; t_vec4 : %lu ; moi : %lu moi deref : %lu\n", sizeof(t_vec3), sizeof(t_vec4), sizeof(sc->f_array[count]), sizeof(*(sc->f_array[count])));
	}
}

int	main(int argc, char *argv[])
{
	t_scop	sc;

	//init(&sc);
	ft_bzero(&sc, sizeof(sc));
	if (argc > 1)
		read_file(argv[1], &sc);
	read_array(&sc);
	return (0);
	const GLubyte* renderer = glGetString(GL_RENDERER); // get renderer string
	const GLubyte* version = glGetString(GL_VERSION); // version as a string
	printf("Renderer: %s\n", renderer);
	printf("OpenGL version supported %s\n", version);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	float points[] = {
		0.0f,  0.5f,  0.0f,
		0.5f, -0.5f,  0.0f,
		-0.5f, -0.5f,  0.0f
	};

	GLuint vbo = 0;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);

	GLuint vao = 0;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	const char* vertex_shader =
	"#version 410\n"
	"in vec3 vp;"
	"void main() {"
	"  gl_Position = vec4(vp, 1.0);"
	"}";

	const char* fragment_shader =
	"#version 410\n"
	"out vec4 frag_colour;"
	"void main() {"
	"  frag_colour = vec4(0.0, 1.0, 0.0, 1.0);"
	"}";

	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vertex_shader, NULL);
	glCompileShader(vs);
	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fragment_shader, NULL);
	glCompileShader(fs);

	GLuint shader_programme = glCreateProgram();
	glAttachShader(shader_programme, fs);
	glAttachShader(shader_programme, vs);
	glLinkProgram(shader_programme);

	while (!glfwWindowShouldClose(sc.win))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(shader_programme);
		glBindVertexArrayAPPLE(vao);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glfwPollEvents();
		glfwSwapBuffers(sc.win);
	}
	glfwTerminate();
	return (0);
}
