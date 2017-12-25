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

typedef struct			s_scop_list
{
	int					id;
	void				*content;
	struct s_scop_list	*next;
}						t_scop_list;

typedef struct			s_scop
{
	t_scop_list			*tmp_list;
	GLFWwindow			*win;
}						t_scop;

void					check_fd(int fd);
void					init(t_scop *s);
t_scop_list				*new_scop_lst(int id, void *content);
void					push_scop_lst(t_scop_list **list, t_scop_list *new);
