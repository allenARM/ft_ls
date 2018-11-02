/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 19:41:11 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/01 20:27:58 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_node	*parse_args(int argc, char **argv, t_flags *flags)
{
	int			i;
	int			read;
	t_node		*path;
	struct stat buf;

	i = 0;
	read = 0;
	path = NULL;
	while (++i < argc)
	{
		if (read == 0 && argv[i][0] == '-' && ft_strcmp(argv[i], "--"))
			fl_set(&argv[i][1], flags);
		if (read || argv[i][0] != '-' || ft_strcmp(argv[i], "-") == 0)
		{
			read = 1;
			lstat(argv[i], &buf);
			path = node_add(path, argv[i], buf);
		}
	}
	if (read == 0)
	{
		lstat(".", &buf);
		path = node_add(path, ".", buf);
	}
	return (path);
}

int		main(int argc, char **argv)
{
	t_node		*path;
	t_flags		flags;

	fl_init(&flags);
	path = parse_args(argc, argv, &flags);
	if (flags.flag_illegal == 1)
		return (0);
	path = path_search_errors(path);
	path = path_apply_flag(path, &flags);
	display_symlink(path, &flags);
	display_blocks(path, &flags);
	display_files(path, &flags);
	display_dirs(path, &flags, 0);
	ft_list_clean(&path);
	return (0);
}
