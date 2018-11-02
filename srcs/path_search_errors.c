/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_search_errors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 19:42:23 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/01 16:45:20 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

t_node	*path_search_errors(t_node *path)
{
	t_node	*root;
	char	*str;

	path = node_sort_by_name(path, 0);
	root = path;
	while (path)
	{
		str = delete_slash(path->name);
		if (stat(path->name, &path->buf) && stat(str, &path->buf) && \
					lstat(path->name, &path->buf))
			ft_printf("b_ls: %s: No such file or directory\n", path->name);
		if (stat(path->name, &path->buf) && !stat(str, &path->buf) && \
					lstat(path->name, &path->buf))
			ft_printf("b_ls: %s: Not a directory\n", path->name);
		free(str);
		path = path->next;
	}
	ft_list_clean(&path);
	return (root);
}
