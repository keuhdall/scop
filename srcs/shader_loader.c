/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader_loader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 23:05:01 by lmarques          #+#    #+#             */
/*   Updated: 2018/08/04 19:20:41 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

char	*get_file_content(char *name)
{
	int			fd;
	char		*file_content;
	struct stat	stat;

	fd = open(name, O_RDONLY);
	fstat(fd, &stat);
	if (!(file_content = (char *)malloc(sizeof(char) * (stat.st_size + 1))))
		puterr(ERR_MALLOC_FAILED);
	if (read(fd, file_content, stat.st_size) == -1)
		puterr(ERR_OPEN_FILE);
	file_content[stat.st_size] = '\0';
	close(fd);
	return (file_content);
}

GLuint	get_vertex_shader(char *vs_name)
{
	const char	*vs_content = get_file_content(vs_name);
	char		*log_msg;
	int			log_length;
	GLuint		vs_id;
	GLint		result;

	vs_id = glCreateShader(GL_VERTEX_SHADER);
	log_length = 0;
	result = GL_FALSE;
	glShaderSource(vs_id, 1, &vs_content, NULL);
	glCompileShader(vs_id);
	glGetShaderiv(vs_id, GL_COMPILE_STATUS, &result);
	glGetShaderiv(vs_id, GL_INFO_LOG_LENGTH, &log_length);
	if (log_length > 0)
	{
		if (!(log_msg = (char *)malloc(sizeof(char) * log_length + 1)))
			puterr(ERR_MALLOC_FAILED);
		glGetShaderInfoLog(vs_id, log_length, NULL, log_msg);
		dprintf(2, "%s\n", log_msg);
		exit(1);
	}
	return (vs_id);
}

GLuint	get_fragment_shader(char *fs_name)
{
	const char	*fs_content = get_file_content(fs_name);
	char		*log_msg;
	int			log_length;
	GLuint		fs_id;
	GLint		result;

	fs_id = glCreateShader(GL_FRAGMENT_SHADER);
	log_length = 0;
	result = GL_FALSE;
	glShaderSource(fs_id, 1, &fs_content, NULL);
	glCompileShader(fs_id);
	glGetShaderiv(fs_id, GL_COMPILE_STATUS, &result);
	glGetShaderiv(fs_id, GL_INFO_LOG_LENGTH, &log_length);
	if (log_length > 0)
	{
		if (!(log_msg = (char *)malloc(sizeof(char) * log_length + 1)))
			puterr(ERR_MALLOC_FAILED);
		glGetShaderInfoLog(fs_id, log_length, NULL, log_msg);
		dprintf(2, "%s\n", log_msg);
		exit(1);
	}
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
	glGetShaderiv(program_id, GL_INFO_LOG_LENGTH, &log_length);
	if (log_length > 0)
		puterr(ERR_CREATING_PROGRAM);
	glDetachShader(program_id, vs_id);
	glDetachShader(program_id, fs_id);
	glDeleteShader(fs_id);
	glDeleteShader(vs_id);
	return (program_id);
}
