/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 19:41:52 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/02 13:01:19 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	illegalfn(t_flags *flags, char *str)
{
	if (*str == 'S')
		flags->flag_sc = 1;
	else if (*str == 'T')
		flags->flag_tc = 1;
	else if (*str == 'G')
		flags->flag_gc = 1;
	else if (*str == 'R')
		flags->flag_cr = 1;
	else
		flags->flag_illegal = 1;
	if (flags->flag_illegal == 1)
	{
		ft_printf("b_ls: illegal option -- %c\n", str);
		ft_printf("usage: ./b_ls [GSTaglrt] [file ...]\n");
	}
}

void	fl_set(char *str, t_flags *flags)
{
	while (*str != '\0' && flags->flag_illegal == 0)
	{
		if (*str == 'l')
			flags->flag_l = 1;
		else if (*str == 'a')
			flags->flag_a = 1;
		else if (*str == 't')
			flags->flag_t = 1;
		else if (*str == 'r')
			flags->flag_r = 1;
		else if (*str == 'n')
		{
			flags->flag_n = 1;
			flags->flag_l = 1;
		}
		else if (*str == 'g')
		{
			flags->flag_g = 1;
			flags->flag_l = 1;
		}
		else
			illegalfn(flags, str);
		str++;
	}
}
