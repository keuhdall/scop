/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:05:10 by lmarques          #+#    #+#             */
/*   Updated: 2018/11/27 13:12:55 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

void	read_arrays(t_scop *sc)
{
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

void	print_v(t_scop *sc)
{
	for (int i = 0; i < sc->v_size; i++) {
		printf("%f %f %f", sc->v_array[i].x, sc->v_array[i].y, sc->v_array[i].z);
		if (i == sc->v_size - 1)
			printf("\n");
		else
			printf(" ; ");
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
	t_scop	sc;

	ft_bzero(&sc, sizeof(sc));
	if (argc > 1)
		read_file(argv[1], &sc);
	check_f(&sc);
	init(&sc);
//	read_arrays(&sc);
	resolve_f(&sc);
	//print_v(&sc);
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

	GLuint program_id = 0;
	if (sc.vt_size)
		program_id = load_shaders("/Users/lmarques/Desktop/scop/srcs/shaders/obj.vert", "/Users/lmarques/Desktop/scop/srcs/shaders/obj.frag");
	else
		program_id = load_shaders("/Users/lmarques/Desktop/scop/srcs/shaders/basic.vert", "/Users/lmarques/Desktop/scop/srcs/shaders/basic.frag");

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
		glDrawArrays(GL_TRIANGLES, 0, sc.v_size);
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);
		glfwSwapBuffers(sc.win);
		glfwPollEvents();
		sc.time.last = sc.time.curr;
	}
	glfwTerminate();
	return (0);
}
