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

int	is_bin(char **argv)
{
	int		i;
	char	*bins[] = {"csh", "ed", "launchctl", "mv", "rmdir", "tcsh",
		"bash", "date", "expr", "link", "pax", "sh", "test", "cat",
		"dd", "hostname", "ln", "ps", "sleep", "unlink", "chmod",
		"df", "kill", "ls", "pwd", "stty", "wait4path", "cp",
		"echo", "ksh", "mkdir", "rm", "sync", "zsh", "\0"};

	i = 0;
	while (bins[i][0])
	{
		if (ft_strcmp(argv[0], bins[i++]) == 0)
			return (1);
	}
	return (0);
}

static void bin_handler(char **argv, char ***env)
{
	pid_t	pid;
	// pid_t	wpid;
	int		status;
	char	*path;

	status = 0;
	pid = fork();
	if (pid == 0)
	{
		if (argv[0][0] != '/' && is_bin(argv))
		{
			path = ft_strjoin("/bin/", argv[0]);
			if (path && execve(path, argv, *env) == -1)
				printf("cd: no such file or directory: %s\n", path);
			else if (path)
				free(path);
			return;
		}
		else if (execve(argv[0], argv, *env) == -1)
			printf("cd: no such file or directory: %s\n", argv[0]);
		// return ;
	}
	return ;
}

static void call_handler(char **argv, char ***env)
{
	if (!argv[0])
		return ;
	if ((ft_strcmp(argv[0], "echo") == 0) || (ft_strcmp(argv[0], "/usr/bin/echo") == 0))
		do_echo(argv, *env);
	else if (ft_strcmp(argv[0], "cd") == 0 || (ft_strcmp(argv[0], "/usr/bin/cd") == 0))
		do_cd(argv, *env);
	else if (ft_strcmp(argv[0], "setenv") == 0 || (ft_strcmp(argv[0], "/usr/bin/setenv") == 0))
		ft_setenv(*env, argv[1], argv[2]);
	else if (ft_strcmp(argv[0], "env") == 0 || (ft_strcmp(argv[0], "/usr/bin/env") == 0))
		ft_putenv(*env);
	else if (ft_strcmp(argv[0], "unsetenv") == 0 || (ft_strcmp(argv[0], "/usr/bin/unsetenv") == 0)) 
		ft_unsetenv(*env, argv[1]);
	else if (ft_strcmp(argv[0], "exit") == 0 || (ft_strcmp(argv[0], "/usr/bin/exit") == 0))
	{
		ft_tabfree(*env);
		exit(argv[1] ? ft_atoi(argv[1]) : 0);
	}
	else if (argv[0][0] == '/' || is_bin(argv))
		bin_handler(argv, env);
	else if (argv[0])
		printf("minishell: %s: command not found\n", argv[0]);
}

int		main(int argc, char **argv, char **envv)
{
	char *input;
	char **env;
	char **args;

	(void)(argc && argv);
		input = NULL;
	env = ft_tabdup(envv);
	printf("%s", handler("/goinfre/$USER/Desktop", env));
	while (1)
	{
		ft_putstr("$> ");
		input = readline("");
		if (input && *input)
		{
			args = ft_strsplit(input, ' ');
			call_handler(args, &env);
			ft_tabfree(args);
		}
	}
	if (env)
		free(&env);
	// return (0);
	// printf("%s", ft_find_variable("/goinfre/$USER/Desktop"));
	return(0);
}

