/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaloyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:12:18 by mbaloyi           #+#    #+#             */
/*   Updated: 2018/09/13 11:16:29 by mbaloyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static void print_echo(char **arg, char **env, int i, int k)
{
	while (arg[k][i] != '\0')
	{
		if (IS_VAR(arg[k][i]))
		{
			check_env_var(arg[k], env);
			break;
		}
		if(IS_QOUTE(arg[k][i]))
			i++;
		if(arg[k][i] == '\0')
			break;
		ft_putchar(arg[k][i]);
		i++;
	}
}

void 	do_echo(char **arg, char **env)
{
	int		i;
	int		k;
	int		count;

	i = 0;
	k = 1;
	count = 0;
	while (arg[count] != '\0')
		count++;
	while (arg[k] != '\0')
	{
		print_echo(arg, env, i, k);
		i = 0;
		if (k != count)
			ft_putchar(' ');
		k++;
	}
	ft_putchar('\n');
}
