/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode_select.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 19:42:14 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/01 15:16:37 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	mode_select(mode_t mode, char *c)
{
	if ((mode & S_IFDIR) == S_IFDIR)
		*c = 'd';
	if ((mode & S_IFCHR) == S_IFCHR)
		*c = 'c';
	if ((mode & S_IFIFO) == S_IFIFO)
		*c = 'p';
	if ((mode & S_IFBLK) == S_IFBLK)
		*c = 'b';
	if ((mode & S_IFREG) == S_IFREG)
		*c = '-';
	if ((mode & S_IFLNK) == S_IFLNK)
		*c = 'l';
	if ((mode & S_IFSOCK) == S_IFSOCK)
		*c = 's';
}
