/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_sorter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 19:42:48 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/01 15:16:37 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

t_node	*node_sort_by_name(t_node *head, int r)
{
	t_node *b;
	t_node *s;

	b = head;
	while (b)
	{
		s = head;
		while (s->next)
		{
			if (r ? ft_strcmp(s->name, s->next->name) < 0 :
					ft_strcmp(s->name, s->next->name) > 0)
				node_swap(s, s->next);
			s = s->next;
		}
		b = b->next;
	}
	free(b);
	return (head);
}

t_node	*node_sort_by_size(t_node *head, int r)
{
	t_node *b;
	t_node *s;

	b = head;
	while (b)
	{
		s = head;
		while (s->next)
		{
			if (r ? s->buf.st_size > s->next->buf.st_size :
					s->buf.st_size < s->next->buf.st_size)
				node_swap(s, s->next);
			s = s->next;
		}
		b = b->next;
	}
	return (head);
}

t_node	*node_sort_by_time(t_node *head, int r)
{
	t_node *b;
	t_node *s;

	b = head;
	while (b)
	{
		s = head;
		while (s->next)
		{
			if (r ? s->buf.st_mtime > s->next->buf.st_mtime :
					s->buf.st_mtime < s->next->buf.st_mtime)
				node_swap(s, s->next);
			if (s->buf.st_mtime == s->next->buf.st_mtime)
				if (r ? s->buf.st_mtimespec.tv_nsec >
						s->next->buf.st_mtimespec.tv_nsec :
						s->buf.st_mtimespec.tv_nsec <
						s->next->buf.st_mtimespec.tv_nsec)
					node_swap(s, s->next);
			s = s->next;
		}
		b = b->next;
	}
	return (head);
}
