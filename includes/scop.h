/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:06:09 by lmarques          #+#    #+#             */
/*   Updated: 2018/03/18 17:40:13 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include <stdio.h>
# include <math.h>
# include <GL/glew.h>
# include <OpenGL/gl.h>
# include <OpenGL/glu.h>
# include <GLFW/glfw3.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define LINE_SIZE 1024

enum	e_errors
{
	ERR_INIT_GLFW,
	ERR_INIT_GLEW,
	ERR_OPEN_WIN,
	ERR_BAD_FORMAT,
	ERR_MALLOC_FAILED,
	ERR_OPEN_FILE
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

typedef struct			s_vec4
{
	float				x;
	float				y;
	float				z;
	float				w;
}						t_vec4;

typedef struct			s_face
{
	int					v_size;
	int					vt_size;
	int					vn_size;
	int					*v;
	int					*vt;
	int					*vn;
}						t_face;

typedef struct			s_scop
{
	int					v_size;
	int					vt_size;
	int					vn_size;
	int					f_size;
	t_vec3				*v_array;
	t_vec2				*vt_array;
	t_vec3				*vn_array;
	t_face				*f_array;
	GLFWwindow			*win;
}						t_scop;

t_vec3					sum3_c(t_vec3 a, float b);
t_vec3					diff3_c(t_vec3 a, float b);
t_vec3					prod3_c(t_vec3 a, float b);
t_vec3					quo3_c(t_vec3 a, float b);

t_vec3					sum3(t_vec3 a, t_vec3 b);
t_vec3					diff3(t_vec3 a, t_vec3 b);
t_vec3					prod3(t_vec3 a, t_vec3 b);
t_vec3					quo3(t_vec3 a, t_vec3 b);
t_vec3					cross3(t_vec3 a, t_vec3 b);
t_vec3					normalize(t_vec3 v);
float					dot(t_vec3 a, t_vec3 b);

int						get_array_size(char **a);
int						count_char(char *s, const char c);
void					free_array(char **a);
void					puterr(const int err);

void					read_file(char *name, t_scop *s);

void					init(t_scop *s);

void					parse_v(char *line, t_scop *s);
void					parse_vt(char *line, t_scop *s);
void					parse_vn(char *line, t_scop *s);
void					parse_f(char *line, t_scop *s);

#endif
