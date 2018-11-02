/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_apply_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 19:42:18 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/01 15:16:37 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

t_node	*path_apply_flag(t_node *path, t_flags *flags)
{
	int		rev;

	rev = 0;
	if (flags->flag_r == 1)
		rev = 1;
	path = node_sort_by_name(path, rev);
	if (flags->flag_t == 1 && flags->flag_sc == 0)
		path = node_sort_by_time(path, rev);
	if (flags->flag_sc == 1)
		path = node_sort_by_size(path, rev);
	return (path);
}
