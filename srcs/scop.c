/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:05:10 by lmarques          #+#    #+#             */
/*   Updated: 2017/12/17 18:17:51 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

int	main(int argc, char *argv[])
{
	t_scop	s;

	if (!argc)
		ft_putendl(argv[0]);
	init_window(&s);
	while (!glfwWindowShouldClose(s.win))
		glfwPollEvents();
	return (0);
}
