/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaloyi <mbaloyi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:12:18 by mbaloyi           #+#    #+#             */
/*   Updated: 2019/07/17 09:22:25 by mbaloyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void	ft_runshel(char **arg, int i, char *path, char **env)
{
	while (arg[i] != '\0')
		{
			if (ft_strcmp(arg[i], "pwd") == 0)
			{	
				path = getcwd(path, sizeof(path));
				ft_printf("%s\n", path);
				free(path);
				path = NULL;
			}
			else if (ft_strcmp(arg[i], "echo") == 0)
				do_echo(arg, env);
			else if (ft_strcmp(arg[i], "cd") == 0)
			 	do_cd(arg, env);
			else if (ft_strcmp(arg[i], "setenv") == 0)
				do_setenv(arg, &env);
			// else if (ft_strcmp(arg[i], "unsetenv"))
			// 	do_unsetenv(arg, env);
			else if (ft_strcmp(arg[i], "env") == 0)
			 	do_env(env);
			else if (ft_strcmp(arg[i], "exit") == 0)
			 	do_exit(arg);
			// else if(arg)
			//  	ft_printf("minishell: command not found: %s\n",arg[i]);
			i++;
		}
}

int	main(int ac, char **av, char **envp)
{
	char	*input;
	char	**arg;
	char	*path;
	int		i;
	char	**env;

	i = 0;
	env = ft_strcpy_double(envp);
	path = NULL;
	(void)(ac && av);
	while (1)
	{
		ft_input();
		input = NULL;
		get_next_line(0, &input);
		arg = ft_strsplit(input, ' ');
		free(input);
		ft_runshel(arg, i, path, env);
		i = 0;
	}
	return (0);
}