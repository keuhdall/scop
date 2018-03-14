/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 17:36:30 by lmarques          #+#    #+#             */
/*   Updated: 2018/03/14 02:28:09 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, int size)
{
	char	*new;

	if (!size && ptr)
	{
		if (!(new = (char *)malloc(1)))
			return (NULL);
		ft_memdel(&ptr);
		return (new);
	}
	if (!(new = (char *)malloc(size)))
		return (NULL);
	if (ptr)
	{
		ft_memcpy(new, ptr, size);
		ft_memdel(&ptr);
	}
	return (new);
}
