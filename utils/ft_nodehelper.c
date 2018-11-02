/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodehelper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 19:42:38 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/01 15:16:37 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	node_copy(t_node *src, t_node *dst)
{
	t_node *temp;

	temp = dst;
	temp->name = src->name;
	temp->buf = src->buf;
}

t_node	*node_remove_hidden(t_node *head)
{
	t_node	*current;

	current = head;
	while (current && current->name[0] == '.')
		head = current->next;
	while (current && current->next)
	{
		if (current->next->name[0] == '.')
			current->next = current->next->next;
		current = current->next;
	}
	return (head);
}

int		node_size(t_node *head)
{
	int		i;
	t_node	*entity;

	i = 0;
	if (head)
	{
		entity = head;
		while (entity)
			(entity = entity->next) && i++;
	}
	return (i);
}

void	node_swap(t_node *one, t_node *two)
{
	t_node *temp;

	temp = (t_node *)malloc(sizeof(t_node));
	node_copy(one, temp);
	node_copy(two, one);
	node_copy(temp, two);
	free(temp);
}
