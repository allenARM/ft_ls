/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_entity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 19:41:27 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/02 13:07:49 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static void			display_detail(t_node *entity, t_flags *flags)
{
	char			c;

	mode_select(entity->buf.st_mode, &c);
	ft_printf("%s%c", CWHITE, c);
	ft_printf("%s", mode_print(entity->buf.st_mode));
	ft_printf("%3i ", entity->buf.st_nlink);
	if (flags->flag_g == 0)
	{
		if (flags->flag_n == 0)
			ft_printf("%-8s  ", getpwuid(entity->buf.st_uid)->pw_name);
		else
			ft_printf("%-7d", entity->buf.st_uid);
	}
	if (flags->flag_n == 0)
		ft_printf("%-7s", getgrgid(entity->buf.st_gid)->gr_name);
	else
		ft_printf("%-6d", entity->buf.st_gid);
	ft_printf("%6lld ", entity->buf.st_size);
	if (flags->flag_tc == 0)
		ft_printf("%6.12s ", ctime(&entity->buf.st_mtime) + 4);
	else
		ft_printf("%.20s ", ctime(&entity->buf.st_mtime) + 4);
}

void				option_for_entity(t_node *path, t_node *entity, t_flags \
						*flags)
{
	char *str;

	if (flags->flag_l == 1)
		display_detail(entity, flags);
	if (flags->flag_gc == 1)
		print_with_colors(entity);
	else
		ft_printf("%s", entity->name);
	str = getting_full_symlink(entity->name, path->name);
	if ((entity->buf.st_mode & S_IFLNK) == S_IFLNK && flags->flag_l == 1)
		ft_printf("%s%s", CWHITE, str);
	if (ft_strcmp(str, " ") != 0)
		free(str);
	ft_printf("%s\n", CWHITE);
}

void				display_entity(t_node *path, t_node *entity, t_flags *flags)
{
	long long		blocks;

	if (entity == NULL || path == NULL)
		return ;
	blocks = count_blocks(entity);
	entity = fl_apply(entity, flags);
	if ((path->buf.st_mode & S_IFDIR) == S_IFDIR
			&& flags->flag_l == 1 && flags->entity_fill == 0)
		ft_printf("total %lld\n", blocks);
	while (entity)
	{
		option_for_entity(path, entity, flags);
		entity = entity->next;
	}
}
