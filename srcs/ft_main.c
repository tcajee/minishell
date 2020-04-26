/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaloyi <mbaloyi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:12:18 by mbaloyi           #+#    #+#             */
/*   Updated: 2019/09/19 18:07:55 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

void call_handler(char **argv, char ***env)
{
	if (!argv[0])
		return ;
	if ((ft_strcmp(argv[0], "echo") == 0)) 
		do_echo(argv, *env);
	else if (ft_strcmp(argv[0], "cd") == 0)
		do_cd(argv, *env);
	else if (ft_strcmp(argv[0], "setenv") == 0)
		ft_setenv(*env, argv[1], argv[2]);
	else if (ft_strcmp(argv[0], "env") == 0)
		ft_putenv(*env);
	else if (ft_strcmp(argv[0], "unsetenv") == 0)
		ft_unsetenv(*env, argv[1]);
	else if (ft_strcmp(argv[0], "exit") == 0)
	{
		ft_tabfree(*env);
		exit(argv[1] ? ft_atoi(argv[1]) : 0);
	}
	else if (get_path(argv, *env))
		return;
	else
		ft_printf("minishell: %s: command not found\n", argv[0]);
}

int		main(int argc, char **argv, char **envv)
{
	char *input;
	char **env;
	char **args;

	(void)(argc && argv);
	env = ft_tabdup(envv);
	while ((input = readline("")))
	{
		args = ft_strsplit(input, ' ');
		call_handler(args, &env);
		ft_tabfree(args);
	}
	if (env)
		free(&env);
	return(0);
}

// fix prompt
// fix echo
// fix cd more than two args