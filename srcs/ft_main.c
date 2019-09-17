/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaloyi <mbaloyi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:12:18 by mbaloyi           #+#    #+#             */
/*   Updated: 2019/09/17 18:00:31 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

char	**ft_strcpy_double(char **arr)
{
	int		k;
	int		i;
	char	**big;
	k = ft_strlen_double(arr);
	i = 0;
	if (!(big = (char **)malloc(sizeof(char *) * (k + 1))))
		return (NULL);
	big[k + 1] = NULL;
	while (i != k)
	{
		big[i] = ft_strnew(ft_strlen(arr[i]));
		ft_strcpy(big[i], arr[i]);
		i++;
	}
	return (big);
}

static void call_handler(char **argv, char ***env)
{
	char *path;

	/* path = (char *)malloc(sizeof(char) * PATH_MAX + 1); */
	(void)env;
	if (!argv[0])
		return ;
	else if (ft_strcmp(argv[0], "pwd") == 0)
	{
		path = (char *)malloc(sizeof(char) * 1024 + 1);
		path[1024 + 1] = '\0';
		path = getcwd(path, 1025);
		/* ft_printf("%s\n", path); */
		printf("%s\n", path);
		if (path)
			free(path);
	}
	else if (ft_strcmp(argv[0], "echo") == 0)
		do_echo(argv, *env);
	/* else if (ft_strcmp(argv[0], "echo") == 0) */
	/* 	mini_echo(argv); */
	else if (ft_strcmp(argv[0], "cd") == 0)
		do_cd(argv, *env);
	else if (ft_strcmp(argv[0], "setenv") == 0)
		ft_setenv(*env, argv[1], "hellO");
	/* else if (ft_strcmp(arg[i], "setenv") == 0) */
	/* 	do_setenv(arg, &env); */
	else if (ft_strcmp(argv[0], "env") == 0)
		do_env(*env);
	/* else if (ft_strcmp(argv[0], "env") == 0) */
	/* 	ft_putenv(*env); */
	else if (ft_strcmp(argv[0], "unsetenv") == 0)
		ft_unsetenv(*env, argv[1]);
	/* else if (ft_strcmp(argv[0], "unsetenv")) */
	/* 	do_unsetenv(argv, env); */
	else if (ft_strcmp(argv[0], "exit") == 0)
	{
		ft_tabfree(*env);
		exit(argv[1] ? ft_atoi(argv[1]) : 0);
	}
	/* else if (ft_strcmp(argv[0], "exit") == 0) */
	/* 	do_exit(argv); */
	else if (argv[0])
		/* ft_printf("minishell: command not found: %s\n",arg[i]); */
		printf("minishell: command not found: %s\n",argv[0]);
}

int		input_handler(const char *input, char ***env)
{
	char **args;

	args = ft_strsplit(input, ' ');
	/* do_env(args); */
	call_handler(args, env);
	ft_tabfree(args);
	return (0);
}

char    **ft_tabdup(char **tab)
{
	int     i;
	int     len;
	char    **cpy;

	if (tab)
	{
		i = 0;
		len = ft_tablen(tab);
		if (!(cpy = (char**)malloc(sizeof(char *) * (len + 1))))
			return (NULL);
		while (i < len)
		{
			cpy[i] = ft_strdup(tab[i]);
			i++;
		}
		cpy[i] = NULL;
		return (cpy);
	}
	return (NULL);
}

int		main(int argc, char **argv, char **envv)
{
	char *input;
	char **env;

	(void)(argc && argv);
	env = ft_tabdup(envv);
	ft_putstr("$> ");
	input = NULL;
	while (1)
	{
		get_next_line(0, &input);
		if (*input)
			input_handler(input, &env);
		ft_putstr("$> ");
	}
	if (env)
		free(&env);
	return (0);
}

/* void	do_exit(char **arg) */
/* { */
/* 	free(arg); */
/* 	exit(0); */
/* } */

/* void	ft_runshel(char **arg, int i, char *path, char **env) */
/* { */
/* 	while (arg[i]) */
/* 		{ */
/* 			if (ft_strcmp(arg[i], "pwd") == 0) */
/* 			{ */
/* 				path = getcwd(path, sizeof(path)); */
/* 				/1* ft_printf("%s\n", path); *1/ */
/* 				printf("%s\n", path); */
/* 				free(path); */
/* 				path = NULL; */
/* 			} */
/* 			else if (ft_strcmp(arg[i], "echo") == 0) */
/* 				do_echo(arg, env); */
/* 			else if (ft_strcmp(arg[i], "cd") == 0) */
/* 			 	do_cd(arg, env); */
/* 			else if (ft_strcmp(arg[i], "setenv") == 0) */
/* 				do_setenv(arg, &env); */
/* 			 /1* else if (ft_strcmp(arg[i], "unsetenv")) *1/ */
/* 			 /1* 	do_unsetenv(arg, env); *1/ */
/* 			else if (ft_strcmp(arg[i], "env") == 0) */
/* 			 	do_env(env); */
/* 			else if (ft_strcmp(arg[i], "exit") == 0) */
/* 			 	do_exit(arg); */
/* 			 else if(arg) */
/* 			  	/1* ft_printf("minishell: command not found: %s\n",arg[i]); *1/ */
/* 			  	printf("minishell: command not found: %s\n",arg[i]); */
/* 			i++; */
/* 		} */
/* } */


int		ft_strlen_double(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return(i);
}

/* void	ft_input(void) */
/* { */
/* 	char	*path; */
/* 	char	**pathreal; */
/* 	int		last; */
/* 	path = NULL; */
/* 	last = 0; */
/* 	pathreal = NULL; */
/* 	path = getcwd(path, sizeof(path)); */
/* 	if (ft_strcmp(path, "/") == 0) */
/* 		 /1* ft_printf("%s[ %s ]%s%s[$➜] %s", GREEN, *1/ */
/* 		 printf("%s[ %s ]%s%s[$➜] %s", GREEN, */
/* 		path, RESET, RED, RESET); */
/* 	else */
/* 	{ */
/* 		pathreal = ft_strsplit(path, '/'); */
/* 		last = ft_strlen_double(pathreal); */
/* 		printf("%s[ %s ]%s%s[$➜] %s", GREEN, */
/* 		/1* ft_printf("%s[ %s ]%s%s[$➜] %s", GREEN, *1/ */
/* 		pathreal[last - 1], RESET, RED, RESET); */
/* 	} */
/* 	free(path); */
/* 	free(pathreal); */
/* } */

