/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:05:10 by lmarques          #+#    #+#             */
/*   Updated: 2018/03/15 19:25:22 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

int		get_array_size(char **a)
{
	int	count;

	count = -1;
	while (a[++count])
		continue;
	return (count);
}

void	free_array(char **a)
{
	int	count;

	count = -1;
	while (a[++count])
		free(a[count]);
	free(a);
	a = NULL;
}

int		count_char(char *s, const char c)
{
	int	count_s;
	int	count_c;

	count_s = -1;
	count_c = 0;
	while (s[++count_s])
	{
		if (s[count_s] == c)
		count_c++;
	}
	return (count_c);
}

void	puterr(const int err)
{
	if (err == ERR_INIT_GLFW)
		dprintf(2, "Error : failed to initialize GLFW\n");
	else if (err == ERR_INIT_GLEW)
		dprintf(2, "Error : failed to initialize GLEW\n");
	else if (err == ERR_OPEN_WIN)
		dprintf(2, "Error : could not open window\n");
	else if (err == ERR_BAD_FORMAT)
		dprintf(2, "Error : bad format in given file\n");
	else if (err == ERR_MALLOC_FAILED)
		dprintf(2, "Error : an occured while allocating memory, exiting.\n");
	else if (err == ERR_OPEN_FILE)
		dprintf(2, "Error : could not open the file\n");
	exit(1);
}
