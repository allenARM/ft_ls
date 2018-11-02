/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smallfn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 19:42:42 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/01 15:16:37 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	ft_list_clean(t_node **list)
{
	t_node	*link;

	if (*list == NULL)
		return ;
	link = *list;
	if (link->next)
		ft_list_clean(&link->next);
	free(link->name);
	free(*list);
}

int		ft_str_find(char *s1, char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[j])
	{
		if (s1[j] == s2[i])
			++i;
		if (s2[i] == '\0')
			return (1);
		j++;
	}
	return (0);
}
