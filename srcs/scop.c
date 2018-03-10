/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:05:10 by lmarques          #+#    #+#             */
/*   Updated: 2018/03/10 02:30:53 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

void	print_list(t_scop *s)
{
	t_list	*tmp;
	t_obj	*tmp_obj;
	t_vec3	tmp_vec3;
	t_vec4	tmp_vec4;

	tmp = s->tmp_list;
	while (tmp)
	{
		tmp_obj = tmp->content;
		if (((t_obj *)tmp->content)->type == V)
		{
			tmp_vec3 = *(t_vec3 *)((t_obj *)tmp->content)->content;
			printf("V : %f ; %f ; %f\n", tmp_vec3.x, tmp_vec3.y, tmp_vec3.z);
		}
		else if (((t_obj *)tmp->content)->type == F)
		{
			if (sizeof(tmp->content) == sizeof(t_vec3))
			{
				tmp_vec3 = *(t_vec3 *)((t_obj *)tmp->content)->content;
				printf("F : %f ; %f ; %f\n", tmp_vec3.x, tmp_vec3.y, tmp_vec3.z);
			}
			else
			{
				tmp_vec4 = *(t_vec4 *)((t_obj *)tmp->content)->content;
				printf("F : %f ; %f ; %f ; %f\n", tmp_vec4.x, tmp_vec4.y, tmp_vec4.z, tmp_vec4.w);
			}
		}
	}
}

int	main(int argc, char *argv[])
{
	t_scop	sc;

	init(&sc);
	if (argc > 1)
		read_file(argv[1], &sc);
	print_list(&sc);
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
