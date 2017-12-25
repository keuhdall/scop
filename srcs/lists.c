/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:05:10 by lmarques          #+#    #+#             */
/*   Updated: 2017/12/17 18:17:51 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

t_scop_list	*new_scop_lst(int id, void *content)
{
	t_scop_list	*tmp;

	if (!(tmp = (t_scop_list *)malloc(sizeof(t_scop_list))))
		return (NULL);
	tmp->id = id;
	tmp->content = content;
	tmp->next = NULL;
	return (tmp);
}

void		push_scop_lst(t_scop_list **list, t_scop_list *new)
{
	t_scop_list	*tmp;

	tmp = NULL;
	tmp = *list;
	if (!tmp)
		*list = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
