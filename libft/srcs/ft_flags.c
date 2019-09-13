/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:11:56 by tcajee            #+#    #+#             */
/*   Updated: 2019/09/11 15:15:19 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int		ft_flag_check(int *flags, char flag)
{
	if (flag == '1')
		return (*flags = (*flags & ~F_L) | F_1);
	else if (flag == 'l')
		return (*flags = (*flags & ~F_1) | F_L);
	else if (flag == 'g')
		return (*flags = (*flags & ~F_1) | (F_L + F_G));
	else if (flag == 't')
		return ((*flags & F_U) ? *flags : (*flags = (*flags & ~F_0) | F_T));
	else if (flag == 'u')
		return (*flags = (*flags & ~(F_T)) | F_U);
	else if (flag == 'r')
		return ((*flags & F_F) ? *flags : (*flags = (*flags & ~F_0) | F_R));
	else if (flag == 'f')
		return (*flags = (*flags & ~(F_U + F_T + F_R)) | (F_F + F_A));
	else if (flag == 'a')
		return (*flags = (*flags & ~F_0) | F_A);
	else if (flag == 'R')
		return (*flags = (*flags & ~F_D) | F_RR);
	else if (flag == 'd')
		return (*flags = (*flags & ~F_RR) | F_D);
	else if (flag == 'o')
		return (*flags = (*flags & ~F_1) | (F_L + F_O));
	else if (flag == 'F')
		return (*flags = (*flags & ~F_0) | F_FF);
	return (ft_flag_check_(flags, flag));
}

int		ft_flag_check_(int *flags, char flag)
{
	if (flag == 'i')
		return (*flags = (*flags & ~F_0) | F_I);
	exit(ft_error_flag(&flag));
}

int		ft_flags(int *flags, char **argv)
{
	int i;
	int j;

	i = 0;
	*flags = 0;
	F_SET(*flags, F_P, F_1);
	while (argv[++i])
	{
		j = 0;
		if (!argv[i][0] || argv[i][0] != '-')
			return (i);
		else if (!ft_strcmp(argv[i], "--"))
			return (i + 1);
		else if (argv[i][0] == '-' && argv[i][1])
		{
			while (argv[i][++j])
				if (ft_flag_check(flags, argv[i][j]) < 0)
					return (-1);
		}
		else
			return (i);
	}
	return (i);
}
