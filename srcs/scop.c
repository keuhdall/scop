/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:05:10 by lmarques          #+#    #+#             */
/*   Updated: 2018/03/17 16:01:57 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

void	read_arrays(t_scop *sc)
{
	int	count;
	int	count_f;

	count = -1;
	while (++count < sc->v_size)
		printf("v : %f ; %f ; %f\n", sc->v_array[count].x, sc->v_array[count].y, sc->v_array[count].z);
	count = -1;
	while (++count < sc->vt_size)
		printf("vt : %f ; %f\n", sc->vt_array[count].x, sc->vt_array[count].y);
	count = -1;
	while (++count < sc->vn_size)
		printf("vn : %f ; %f ; %f\n", sc->vn_array[count].x, sc->vn_array[count].y, sc->vn_array[count].z);
	count = -1;
	while (++count < sc->f_size)
	{
		count_f = -1;
		printf("f : ");
		while (++count_f < sc->f_array[count].v_size)
		{
			printf("%d/%d/%d", sc->f_array[count].v[count_f], sc->f_array[count].vt[count_f], sc->f_array[count].vn[count_f]);
			if (count_f < sc->f_array[count].v_size - 1)
				printf(" ; ");
		}
		printf("\n");
	}
}

int	main(int argc, char *argv[])
{
	t_scop	sc;

	ft_bzero(&sc, sizeof(sc));
	if (argc > 1)
		read_file(argv[1], &sc);
	init(&sc);
	read_arrays(&sc);
	//while (1) continue ;
	//return (0);
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
