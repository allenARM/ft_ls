/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_slash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 19:41:17 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/01 15:16:37 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

char		*delete_slash(char *str)
{
	size_t	i;
	char	*new;

	i = 0;
	if (str[ft_strlen(str) - 1] != '/')
	{
		new = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
		while (i < ft_strlen(str) - 1)
		{
			new[i] = str[i];
			++i;
		}
		new[i] = '\0';
		return (new);
	}
	new = (char *)malloc(sizeof(char) * ft_strlen(str));
	while (i < ft_strlen(str) - 1)
	{
		new[i] = str[i];
		++i;
	}
	new[i] = '\0';
	return (new);
}
