/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader_loader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 23:05:01 by lmarques          #+#    #+#             */
/*   Updated: 2018/08/04 01:03:25 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

char	*get_file_content(char *name)
{
	int		fd;
	int		ret;
	char	*line;
	char	*file_content;

	file_content = NULL;
	fd = open(name, O_RDONLY);
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
			puterr(ERR_OPEN_FILE);
		ft_realloc(file_content, ft_strlen(file_content) + ft_strlen(line));
		ft_strcat(file_content, line);
		free(line);
	}
	free(line);
	close(fd);
	return (file_content);
}

GLuint	get_vertex_shader(char *vs_name)
{
	const char	*vs_content = get_file_content(vs_name);
	GLuint		vs_id;
	int			log_length;

	vs_id = 0;
	log_length = 0;
	glShaderSource(vs_id, 1, &vs_content, NULL);
	glCompileShader(vs_id);
	glGetShaderiv(vs_id, GL_INFO_LOG_LENGTH, &log_length);
	if (log_length > 0)
		puterr(ERR_LOADING_SHADER);
	return (vs_id);
}

GLuint	get_fragment_shader(char *fs_name)
{
	const char	*fs_content = get_file_content(fs_name);
	GLuint		fs_id;
	int			log_length;

	fs_id = 0;
	log_length = 0;
	glShaderSource(fs_id, 1, &fs_content, NULL);
	glCompileShader(fs_id);
	glGetShaderiv(fs_id, GL_INFO_LOG_LENGTH, &log_length);
	if (log_length > 0)
		puterr(ERR_LOADING_SHADER);
	return (fs_id);
}

GLuint	load_shaders(char *vs_name, char *fs_name)
{
	GLuint	program_id;
	GLuint	vs_id;
	GLuint	fs_id;
	int		log_length;

	log_length = 0;
	program_id = glCreateProgram();
	vs_id = get_vertex_shader(vs_name);
	fs_id = get_fragment_shader(fs_name);
	glAttachShader(program_id, vs_id);
	glAttachShader(program_id, fs_id);
	glLinkProgram(program_id);
	if (log_length > 0)
		puterr(ERR_CREATING_PROGRAM);
	glDetachShader(program_id, vs_id);
	glDetachShader(program_id, fs_id);
	glDeleteShader(fs_id);
	glDeleteShader(vs_id);
	return (program_id);
}
