/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaloyi <mbaloyi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:12:18 by mbaloyi           #+#    #+#             */
/*   Updated: 2019/09/17 16:55:14 by tcajee           ###   ########.fr       */
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



/* {{{TITLE
 

static void call_handler(char **argv, char ***env)
{
	(void)env;
	if (ft_strcmp(argv[0], "echo") == 0)
		mini_echo(argv);
	else if (ft_strcmp(argv[0], "env") == 0)
		ft_putenv(*env);		
	else if (ft_strcmp(argv[0], "setenv") == 0)
		ft_setenv(*env, argv[1], "hellO");
	else if (ft_strcmp(argv[0], "unsetenv") == 0)
		ft_unsetenv(*env, argv[1]);
	else if (ft_strcmp(argv[0], "exit") == 0)
	{
		ft_tabfree(*env);
		exit(argv[1] ? ft_atoi(argv[1]) : 0);
	}
	//free(argv);
}

int		input_handler(const char *input, char ***env)
{
	char **args;

	args = ft_strqotsplit(input);
	call_handler(args, env);
	ft_tabfree(args);
//	printf("%p\n", env);
//	free(args);
//	args = NULL;
//	free(**env);
	return (0);
}
int		main(int argc, char **argv, char **envv)
{
	
	char *input;
	char **env;
	
	(void)(argc && argv);
	env = ft_tabdup(envv); 
	ft_putstr("$>");
	input = NULL;
	while (1)
	{
		get_next_line(0, &input);
		input_handler(input, &env);
		free(input);
		input = NULL;
		ft_putstr("$>");
	}
	free(&env);
	return (0);
}
 
 }}} */
