/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorac <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 08:06:52 by skorac            #+#    #+#             */
/*   Updated: 2018/09/27 13:48:33 by skorac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/minishell.h"


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
