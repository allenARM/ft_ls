/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 19:42:04 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/01 16:31:34 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

char	*mode_print(mode_t mode)
{
	size_t		i;
	static char temp[10];
	static char buf[] = "rwxrwxrwx";

	i = 0;
	while (i < 9)
	{
		temp[i] = (mode & (1 << (8 - i))) ? buf[i] : '-';
		i++;
	}
	temp[i] = '\0';
	if (mode & S_ISUID)
		temp[2] = (mode & S_IXUSR) ? 's' : 'S';
	if (mode & S_ISGID)
		temp[5] = (mode & S_IXGRP) ? 's' : 'S';
	if (mode & S_ISVTX)
		temp[8] = (mode & S_IXOTH) ? 't' : 'T';
	return (temp);
}
