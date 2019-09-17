/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaloyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:12:18 by mbaloyi           #+#    #+#             */
/*   Updated: 2019/09/17 17:27:09 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

static void print_echo(char **arg, char **env, int i, int k)
{
	while (arg[k][i])
	{
		if (!arg[k][i])
			break ;
		if (IS_VAR(arg[k][i]))
		{
			check_env_var(arg[k], env);
			break ;
		}
		if (IS_QOUTE(arg[k][i]))
			i++;
		ft_putchar(arg[k][i]);
		i++;
	}
}


void	check_env_var(char *arg, char **env)
{
	int		i;
	char	**env_var;

	i = 0;
	while(env[i])
	{
		env_var = ft_strsplit(env[i], '=');
		if (ft_strcmp(env_var[0], arg + 1) == 0)
			printf("%s", env_var[1]);
			/* ft_printf("%s", env_var[1]); */
		i++;
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
	/* ft_putchar('\n'); */
}

void	mini_echo(char **argv)
{
	size_t i;

	i = 1;
	while (argv[i])
	{
		ft_putstr((argv[i]));
		ft_putchar(' ');
		i++;
	}
	ft_putstr("\b\n");
}


