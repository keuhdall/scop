/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:06:09 by lmarques          #+#    #+#             */
/*   Updated: 2017/12/17 18:17:33 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <GL/glew.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLFW/glfw3.h>
#include "../libft/libft.h"
#include "../libft/get_next_line.h"

#define WIN_WIDTH 800
#define WIN_HEIGHT 600
#define LINE_SIZE 1024

enum					e_var_type
{
						V,
						VT,
						VN,
						F
};

typedef struct			s_vec2
{
	float				x;
	float				y;
}						t_vec2;

typedef struct			s_vec3
{
	float				x;
	float				y;
	float				z;
}						t_vec3;

typedef struct			s_scop
{
	t_list				*tmp_list;
	GLFWwindow			*win;
}						t_scop;



int						count_array(char **a);
void					free_array(char **a);

void					check_fd(int fd);
void					read_file(char *name, t_scop *s);

void					init(t_scop *s);

void					parse_v(char *line, t_scop *s);
void					parse_vt(char *line, t_scop *s);
void					parse_vn(char *line, t_scop *s);
