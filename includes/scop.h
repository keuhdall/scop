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

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLFW/glfw3.h>
#include "../libft/libft.h"
#include "../libft/get_next_line.h"

typedef struct	s_scop
{
	GLFWwindow	*win;
}				t_scop;

void			check_fd(int fd);
void			init_window(t_scop *s);
