/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getting_full_symlink.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 19:41:58 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/01 15:16:37 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

char				*check_path_and_link(char *link, char *path)
{
	char			*temp;

	if (ft_strcmp(link, path) == 0)
		temp = ft_strjoin(path, "");
	else if (link[0] != '.' && link[0] != '/')
	{
		path = ft_strjoin(path, "/");
		temp = ft_strjoin(path, link);
		free(path);
	}
	else
		temp = ft_strjoin(path, "");
	return (temp);
}

char				*getting_full_symlink(char *link, char *path)
{
	struct stat		buf;
	ssize_t			r;
	char			*linkname;
	char			*temp;

	if (ft_str_find(link, "->") == 1)
		return (" ");
	temp = check_path_and_link(link, path);
	if (lstat(temp, &buf) != -1 && (linkname = malloc(\
					buf.st_size + 1)) != NULL)
	{
		r = readlink(temp, linkname, buf.st_size + 5);
		if (r != -1)
		{
			linkname[r] = '\0';
			free(temp);
			temp = ft_strjoin(" -> ", linkname);
			free(linkname);
			return (temp);
		}
		free(linkname);
	}
	free(temp);
	return (" ");
}

long long			count_blocks(t_node *entity)
{
	t_node			*tmp;
	long long		blocks;

	blocks = 0;
	tmp = entity;
	while (tmp)
	{
		blocks += tmp->buf.st_blocks;
		tmp = tmp->next;
	}
	return (blocks);
}
