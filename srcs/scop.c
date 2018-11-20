/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:05:10 by lmarques          #+#    #+#             */
/*   Updated: 2018/11/20 19:29:37 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

static const GLfloat g_vertex_buffer_data[] = {
	-1.0f,-1.0f,-1.0f, // triangle 1 : begin
	-1.0f,-1.0f, 1.0f,
	-1.0f, 1.0f, 1.0f, // triangle 1 : end
	1.0f, 1.0f,-1.0f, // triangle 2 : begin
	-1.0f,-1.0f,-1.0f,
	-1.0f, 1.0f,-1.0f, // triangle 2 : end
	1.0f,-1.0f, 1.0f,
	-1.0f,-1.0f,-1.0f,
	1.0f,-1.0f,-1.0f,
	1.0f, 1.0f,-1.0f,
	1.0f,-1.0f,-1.0f,
	-1.0f,-1.0f,-1.0f,
	-1.0f,-1.0f,-1.0f,
	-1.0f, 1.0f, 1.0f,
	-1.0f, 1.0f,-1.0f,
	1.0f,-1.0f, 1.0f,
	-1.0f,-1.0f, 1.0f,
	-1.0f,-1.0f,-1.0f,
	-1.0f, 1.0f, 1.0f,
	-1.0f,-1.0f, 1.0f,
	1.0f,-1.0f, 1.0f,
	1.0f, 1.0f, 1.0f,
	1.0f,-1.0f,-1.0f,
	1.0f, 1.0f,-1.0f,
	1.0f,-1.0f,-1.0f,
	1.0f, 1.0f, 1.0f,
	1.0f,-1.0f, 1.0f,
	1.0f, 1.0f, 1.0f,
	1.0f, 1.0f,-1.0f,
	-1.0f, 1.0f,-1.0f,
	1.0f, 1.0f, 1.0f,
	-1.0f, 1.0f,-1.0f,
	-1.0f, 1.0f, 1.0f,
	1.0f, 1.0f, 1.0f,
	-1.0f, 1.0f, 1.0f,
	1.0f,-1.0f, 1.0f
};

static const GLfloat g_color_buffer_data[] = {
	0.583f,  0.771f,  0.014f,
	0.609f,  0.115f,  0.436f,
	0.327f,  0.483f,  0.844f,
	0.822f,  0.569f,  0.201f,
	0.435f,  0.602f,  0.223f,
	0.310f,  0.747f,  0.185f,
	0.597f,  0.770f,  0.761f,
	0.559f,  0.436f,  0.730f,
	0.359f,  0.583f,  0.152f,
	0.483f,  0.596f,  0.789f,
	0.559f,  0.861f,  0.639f,
	0.195f,  0.548f,  0.859f,
	0.014f,  0.184f,  0.576f,
	0.771f,  0.328f,  0.970f,
	0.406f,  0.615f,  0.116f,
	0.676f,  0.977f,  0.133f,
	0.971f,  0.572f,  0.833f,
	0.140f,  0.616f,  0.489f,
	0.997f,  0.513f,  0.064f,
	0.945f,  0.719f,  0.592f,
	0.543f,  0.021f,  0.978f,
	0.279f,  0.317f,  0.505f,
	0.167f,  0.620f,  0.077f,
	0.347f,  0.857f,  0.137f,
	0.055f,  0.953f,  0.042f,
	0.714f,  0.505f,  0.345f,
	0.783f,  0.290f,  0.734f,
	0.722f,  0.645f,  0.174f,
	0.302f,  0.455f,  0.848f,
	0.225f,  0.587f,  0.040f,
	0.517f,  0.713f,  0.338f,
	0.053f,  0.959f,  0.120f,
	0.393f,  0.621f,  0.362f,
	0.673f,  0.211f,  0.457f,
	0.820f,  0.883f,  0.371f,
	0.982f,  0.099f,  0.879f
};

static const GLfloat g_uv_buffer_data[] = {
	0.000059f, 1.0f-0.000004f,
	0.000103f, 1.0f-0.336048f,
	0.335973f, 1.0f-0.335903f,
	1.000023f, 1.0f-0.000013f,
	0.667979f, 1.0f-0.335851f,
	0.999958f, 1.0f-0.336064f,
	0.667979f, 1.0f-0.335851f,
	0.336024f, 1.0f-0.671877f,
	0.667969f, 1.0f-0.671889f,
	1.000023f, 1.0f-0.000013f,
	0.668104f, 1.0f-0.000013f,
	0.667979f, 1.0f-0.335851f,
	0.000059f, 1.0f-0.000004f,
	0.335973f, 1.0f-0.335903f,
	0.336098f, 1.0f-0.000071f,
	0.667979f, 1.0f-0.335851f,
	0.335973f, 1.0f-0.335903f,
	0.336024f, 1.0f-0.671877f,
	1.000004f, 1.0f-0.671847f,
	0.999958f, 1.0f-0.336064f,
	0.667979f, 1.0f-0.335851f,
	0.668104f, 1.0f-0.000013f,
	0.335973f, 1.0f-0.335903f,
	0.667979f, 1.0f-0.335851f,
	0.335973f, 1.0f-0.335903f,
	0.668104f, 1.0f-0.000013f,
	0.336098f, 1.0f-0.000071f,
	0.000103f, 1.0f-0.336048f,
	0.000004f, 1.0f-0.671870f,
	0.336024f, 1.0f-0.671877f,
	0.000103f, 1.0f-0.336048f,
	0.336024f, 1.0f-0.671877f,
	0.335973f, 1.0f-0.335903f,
	0.667969f, 1.0f-0.671889f,
	1.000004f, 1.0f-0.671847f,
	0.667979f, 1.0f-0.335851f
};

void	read_arrays(t_scop *sc)
{
	(void)g_vertex_buffer_data;
	(void)g_uv_buffer_data;
	int	count;
	int	count_f;

	count = -1;
	while (++count < sc->tmp_v_size)
		printf("v : %f ; %f ; %f\n", sc->tmp_v_array[count].x, sc->tmp_v_array[count].y, sc->tmp_v_array[count].z);
	count = -1;
	while (++count < sc->tmp_vt_size)
		printf("vt : %f ; %f\n", sc->tmp_vt_array[count].x, sc->tmp_vt_array[count].y);
	count = -1;
	while (++count < sc->tmp_vn_size)
		printf("vn : %f ; %f ; %f\n", sc->tmp_vn_array[count].x, sc->tmp_vn_array[count].y, sc->tmp_vn_array[count].z);
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
// "Bind" the newly created texture : all future texture functions will modify this texture
		printf("\n");
	}
}

void	print_mat(t_vec4 *mat)
{
	for (int i = 0; i < 4; i++) {
		printf("mat[%d] : %f ; %f ; %f ; %f\n", i, mat[i].x, mat[i].y, mat[i].z, mat[i].w);
	}
}

void	recalc_mvp(t_scop *sc)
{
	free(sc->mvp);
	t_vec4	*model_m;
	t_vec4	*view_m;
	t_vec4	*projection_m;
	float	f[4];

	projection_m = new_matrix();
	refresh_mouse_view(sc);
	handle_keyboard_input(sc);
	f[0] = degrees_to_rad(sc->cam.fov);
	f[1] = WIN_WIDTH / WIN_HEIGHT;
	f[2] = 0.1f;
	f[3] = 100.0f;
	perspective(projection_m, f);
	view_m = lookat(sc->cam.cam_pos, sum3(sc->cam.cam_pos, sc->cam.cam_dir),
		sc->cam.up_vec);
	model_m = new_identity_m();
	sc->mvp = mvp(model_m, view_m, projection_m);
	free(model_m);
	free(view_m);
	free(projection_m);
}

int	main(int argc, char *argv[])
{
	(void)g_color_buffer_data;
	t_scop	sc;

	ft_bzero(&sc, sizeof(sc));
	if (argc > 1)
		read_file(argv[1], &sc);
	check_f(&sc);
	init(&sc);
	read_arrays(&sc);
	//resolve_f(&sc);
	const GLubyte* renderer = glGetString(GL_RENDERER); // get renderer string
	const GLubyte* version = glGetString(GL_VERSION); // version as a string
	printf("Renderer: %s\n", renderer);
	printf("OpenGL version supported %s\n", version);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	GLuint textureID;
	glGenTextures(1, &textureID);

	glBindTexture(GL_TEXTURE_2D, textureID);

	glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, sc.bmp.width, sc.bmp.height, 0, GL_BGR, GL_UNSIGNED_BYTE, sc.bmp.data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	//GLuint program_id = load_shaders("/Users/lmarques/Desktop/scop/srcs/shaders/test.vert", "/Users/lmarques/Desktop/scop/srcs/shaders/test.frag");
	GLuint program_id = load_shaders("/Users/lmarques/Desktop/scop/srcs/shaders/tex_cube.vert", "/Users/lmarques/Desktop/scop/srcs/shaders/tex_cube.frag");

/*
	GLuint vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	GLuint uvbuffer;
	glGenBuffers(1, &uvbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_uv_buffer_data), g_uv_buffer_data, GL_STATIC_DRAW);
*/
	GLuint vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(t_vec3) * sc.v_size, &sc.v_array[0], GL_STATIC_DRAW);

	GLuint uvbuffer;
	glGenBuffers(1, &uvbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(t_vec2) * sc.vt_size, &sc.vt_array[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
	glVertexAttribPointer(
		1,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		2,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);

	while (!glfwWindowShouldClose(sc.win) &&
			glfwGetKey(sc.win, GLFW_KEY_ESCAPE) != GLFW_PRESS)
	{
		sc.time.curr = glfwGetTime();
		sc.time.delta = (float)(sc.time.curr - sc.time.last);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		recalc_mvp(&sc);//
		GLuint m_id = glGetUniformLocation(program_id, "MVP");
		glUniformMatrix4fv(m_id, 1, GL_TRUE, (const GLfloat *)sc.mvp);
		glUseProgram(program_id);
		glDrawArrays(GL_TRIANGLES, 0, 3*12);
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);
		glfwSwapBuffers(sc.win);
		glfwPollEvents();
		sc.time.last = sc.time.curr;
	}
	glfwTerminate();
	return (0);
}
