/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:05:10 by lmarques          #+#    #+#             */
/*   Updated: 2018/03/14 03:41:57 by lmarques         ###   ########.fr       */
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

void	puterr(int err)
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
	exit(1);
}
