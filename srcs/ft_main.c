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

void	do_exit(char **arg)
{
	free(arg);
	exit(0);
}

void	ft_runshel(char **arg, int i, char *path, char **env)
{
	while (arg[i])
		{
			if (ft_strcmp(arg[i], "pwd") == 0)
			{
				path = getcwd(path, sizeof(path));
				/* ft_printf("%s\n", path); */
				printf("%s\n", path);
				free(path);
				path = NULL;
			}
			else if (ft_strcmp(arg[i], "echo") == 0)
				do_echo(arg, env);
			else if (ft_strcmp(arg[i], "cd") == 0)
			 	do_cd(arg, env);
			else if (ft_strcmp(arg[i], "setenv") == 0)
				do_setenv(arg, &env);
			 /* else if (ft_strcmp(arg[i], "unsetenv")) */
			 /* 	do_unsetenv(arg, env); */
			else if (ft_strcmp(arg[i], "env") == 0)
			 	do_env(env);
			else if (ft_strcmp(arg[i], "exit") == 0)
			 	do_exit(arg);
			 else if(arg)
			  	/* ft_printf("minishell: command not found: %s\n",arg[i]); */
			  	printf("minishell: command not found: %s\n",arg[i]);
			i++;
		}
}


int		ft_strlen_double(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return(i);
	free(str);
}

void	ft_input(void)
{
	char	*path;
	char	**pathreal;
	int		last;

	path = NULL;
	last = 0;
	pathreal = NULL;
	path = getcwd(path, sizeof(path));
	if (ft_strcmp(path, "/") == 0)
		 /* ft_printf("%s[ %s ]%s%s[$➜] %s", GREEN, */
		 printf("%s[ %s ]%s%s[$➜] %s", GREEN,
		path, RESET, RED, RESET);
	else
	{
		pathreal = ft_strsplit(path, '/');
		last = ft_strlen_double(pathreal);
		printf("%s[ %s ]%s%s[$➜] %s", GREEN,
		/* ft_printf("%s[ %s ]%s%s[$➜] %s", GREEN, */
		pathreal[last - 1], RESET, RED, RESET);
	}
	free(path);
	free(pathreal);
}

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


/* int	main(int ac, char **av, char **envp) */
/* { */
/* 	char	*input; */
/* 	char	**arg; */
/* 	char	*path; */
/* 	int		i; */
/* 	char	**env; */
/* 	i = 0; */
/* 	env = ft_strcpy_double(envp); */
/* 	path = NULL; */
/* 	(void)(ac && av); */
/* 	while (1) */
/* 	{ */
/* 		ft_input(); */
/* 		input = NULL; */
/* 		get_next_line(0, &input); */
/* 		arg = ft_strsplit(input, ' '); */
/* 		free(input); */
/* 		ft_runshel(arg, i, path, env); */
/* 		i = 0; */
/* 	} */
/* 	return (0); */
/* } */



static int	find_quote(const char *str, int i)
{
	char *pos;

	i++;
	while ((pos = ft_strchr(str + i, '\"')))
		if (str[i - 1] != '\\')
			break ;
	if (!pos)
		return (0);
	return (pos - str);
}

static int	count_words(char const *str)
{
	int		i;
	int		last_was_split;
	int		count;

	last_was_split = 1;
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			last_was_split = 1;
		else
		{
			if (last_was_split)
				count++;
			if (last_was_split && str[i] == '\"')
				if (!(i = find_quote(str, i)))
					return (0);
			last_was_split = 0;
		}
		i++;
	}
	return (count);
}

static void	fill_array(char **result, char const *str)
{
	int		current_word;
	int		i;
	char	*start;

	i = -1;
	current_word = 0;
	while (str[++i])
		if (str[i] == '\"')
		{
			start = (char *)str + i++ + 1;
			while (str[i] && (str[i] != '\"' || str[i - 1] == '\''))
				i++;
			result[current_word] = *ft_strsplit(start, str + i-- - start);
			current_word++;
		}
		else if ((str[i]) != ' ')
		{
			start = (char *)str + i;
			while ((str[i]) != ' '  && str[i])
				i++;
			result[current_word] = ft_strndup(start, str + i-- - start);
			current_word++;
		}
	result[current_word] = 0;
}

char		**ft_strqotsplit(char const *str)
{
	char		**result;
	size_t		words;

	if (!str)
		return (NULL);
	if (!(words = count_words(str)))
		return (NULL);
	result = malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	fill_array(result, str);
	return (result);
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
		path = getcwd(path, sizeof(path));
		/* ft_printf("%s\n", path); */
		printf("%s\n", path);
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
	else if (ft_strcmp(argv[0], "env") == 0)
		ft_putenv(*env);
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
	
	if (*input)
	{
		args = ft_strqotsplit(input);
		call_handler(args, env);
		ft_tabfree(args);
	}
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
		input_handler(input, &env);
		free(input);
		input = NULL;
		ft_putstr("$> ");
	}
	free(&env);
	return (0);
}
