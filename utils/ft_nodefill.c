/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodefill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 19:42:33 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/01 15:16:37 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

t_node	*createnewlist(struct stat buf, char *name)
{
	t_node *new;

	new = (t_node*)malloc(sizeof(t_node));
	new->name = ft_strdup(name);
	new->buf = buf;
	new->next = NULL;
	return (new);
}

t_node	*node_add(t_node *head, char *name, struct stat buf)
{
	t_node *temp;
	t_node *begin_list;

	if (head == NULL)
		return (createnewlist(buf, name));
	begin_list = head;
	temp = (t_node *)malloc(sizeof(t_node));
	temp->name = ft_strdup(name);
	temp->buf = buf;
	temp->next = NULL;
	while (head->next)
		head = head->next;
	head->next = temp;
	return (begin_list);
}
