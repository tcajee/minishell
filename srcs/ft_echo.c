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

// static void print_echo(char **arg, char **env, int i, int k)
// {
// 	if (IS_VAR(arg[k][i]))
// 		return (check_env_var(arg[k], env));
// 	else if (IS_QUOTE(arg[k][i]))
// 		ft_quotes(arg[k]);
// }

char *ft_quotes(char *str)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		if (IS_SINGLE(str[i]) || IS_DOUBLE(str[i]))
			i++;
		else if ((IS_DOUBLE(str[i - 1]) && IS_DOUBLE(str[i])) ||
				(IS_SINGLE(str[i - 1]) && IS_SINGLE(str[i])) )
		{
			while (str[j])
			{
				if (j == i || j == i - 1)
					j++;
				else
					str[k++] = str[j++];
			}
			str[k] = '\0';
			if ((IS_SINGLE(str[0]) && IS_SINGLE(str[0]) && str[2] == '\0') ||
				(IS_DOUBLE(str[0]) && IS_DOUBLE(str[1]) && str[2] == '\0'))
				return (str);
			else
				ft_quotes(str);
		}
		else
			return (str);
	}
	return (str);
}

void 	do_echo(char **argv, char **env)
{
	int i;
	int j;
	int k;
	char *str;
	char *temp;

	(void)(env);

	k = 1;
	while (argv[k])
	{
		j = 0;
		i = 0;
		temp = ft_strdup(argv[k]);
		while (argv[k][i])
		{
			if (IS_SINGLE(argv[k][i]) || IS_DOUBLE(argv[k][i]))
				argv[k][j++] = argv[k][i++];
			else
				i++;
		}
		argv[k][j] = '\0';
		str = ft_quotes(argv[k]);
		// if (!str)
		// if (str[0] == '\0')
		if ((IS_SINGLE(str[0]) && IS_SINGLE(str[1]) && str[2] == '\0') ||
			(IS_DOUBLE(str[0]) && IS_DOUBLE(str[1]) && str[2] == '\0'))
		{
			ft_putstr("G\n");
			ft_putstr(temp);
			ft_putstr("\n");
		}
		else
		{
			ft_putstr("Error! Bad quotes!");
			ft_putstr(str);
			ft_putstr("\n");
		}
		k++;
		free(temp);
	}
}
