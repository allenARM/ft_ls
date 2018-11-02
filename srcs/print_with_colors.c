/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_with_colors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 19:42:27 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/01 19:42:24 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	print_with_colors(t_node *entity)
{
	if ((entity->buf.st_mode & S_IFBLK) == S_IFBLK)
		ft_printf("%s%s%s%s%s", CBLUE, BBLUE, entity->name, BBLACK, CWHITE);
	else if ((entity->buf.st_mode & S_IFLNK) == S_IFLNK)
		ft_printf("%s%s%s", CPINK, entity->name, CWHITE);
	else if ((entity->buf.st_mode & S_IFDIR) == S_IFDIR)
		ft_printf("%s%s%s", CBLUE, entity->name, CWHITE);
	else if ((entity->buf.st_mode & S_IXUSR) == S_IXUSR)
		ft_printf("%s%s%s", CRED, entity->name, CWHITE);
	else if ((entity->buf.st_mode & S_IFCHR) == S_IFCHR)
		ft_printf("%s%s%s%s%s", CBLUE, BYELLOW, entity->name, BBLACK, CWHITE);
	else
		ft_printf("%s%s%s", CWHITE, entity->name, CWHITE);
}
