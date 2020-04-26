/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaloyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:12:18 by mbaloyi           #+#    #+#             */
/*   Updated: 2019/09/19 12:30:50 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

static void print_echo(char **arg, char **env, int i, int k)
{
	int len;

	if (!arg[k][i])
		return ;
	if (IS_VAR(arg[k][i]))
	{
		check_env_var(arg[k], env);
		return ;
	}
	if (IS_QOUTE(arg[k][i]))
	{
		len = (int)ft_strlen(arg[k]) - 2;
		if (arg[k][i] != arg[k][len + 1])
		{
			ft_putstr("echo Error: Please close quotes.");
			return ;
		}
		while (++i < len + 1)
			ft_putchar(arg[k][i]);
	}
	else
		ft_putstr(arg[k]);
}

void	check_env_var(char *arg, char **env)
{
	int		i;
	char	**env_var;

	i = 0;
	while(env[i])
	{
		env_var = ft_strsplit(env[i++], '=');
		if (ft_strcmp(env_var[0], arg + 1) == 0)
			ft_putstr(env_var[1]);

	}
}

void 	do_echo(char **arg, char **env)
{
	int		k;

	k = 1;
	while (arg[k])
	{
		print_echo(arg, env, 0, k++);
		ft_putchar(' ');
	}
	ft_putstr("\b\n");
}
