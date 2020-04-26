/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaloyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:12:18 by mbaloyi           #+#    #+#             */
/*   Updated: 2019/09/19 12:28:41 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

char *ft_home(char **env)
{
	char 	**home;
	int		i;

	i = 0;
	while(env[i])
	{
		home = ft_strsplit(env[i++], '=');
		if (ft_strcmp(home[0], "HOME") == 0)
		{
			free(home[0]);
			return(home[1]);
		}
		else
			ft_tabfree(home);
	}
	return (NULL);
}

char *ft_oldpwd(char **env)
{
	char 	**home;
	int		i;

	i = 0;
	while(env[i])
	{
		home = ft_strsplit(env[i++], '=');
		if (ft_strcmp(home[0], "OLDPWD") == 0)
		{
			free(home[0]);
			return(home[1]);
		}
		else
			ft_tabfree(home);
	}
	return (NULL);
}

int			ft_is_dir(char *dir)
{
	struct stat		s_is;

	if (lstat(dir, &s_is) < 0)
		ft_printf("cd: no such file or directory: %s\n", dir);
	else if ((s_is.st_mode & S_IFMT) == S_IFLNK)
		return (2);
	else if ((s_is.st_mode & S_IFMT) == S_IFDIR)
	{
		if ((!(s_is.st_mode & S_IRGRP) && !(s_is.st_mode & S_IRUSR) && !(s_is.st_mode & S_IROTH)))
		{
			ft_printf("minishell: cd: %s: Permission denied\n", dir);
			return (0);
		}
		return (1);
	}
	return (0);
}

void	do_cd(char **arg, char **env)
{
	char	*new;
	char	*temp;
	char	*old;
	char	path[PATH_MAX];
	
	old = NULL;
	new = NULL;
	old = getcwd(old, 1024);
	if (arg[2])
		ft_printf("minishell: cd: too many arguments\n");
	if (!arg[1] || (ft_strcmp(arg[1], "--") == 0) || (ft_strcmp(arg[1], "$HOME") == 0) || (ft_strcmp(arg[1], "~") == 0))
		chdir(new = ft_home(env));
	else if ((ft_strcmp(arg[1], "-") == 0) || (ft_strcmp(arg[1], "$OLDPWD") == 0))
		chdir(new = ft_oldpwd(env));
	else if (ft_is_dir(arg[1]) == 2)
	{
		readlink(arg[1], ft_memset(path, 0, PATH_MAX), PATH_MAX);
		temp = ft_strsub(arg[1], 0, (ft_strrchr(arg[1], '/') - arg[1] + 1 ));
		new = ft_strjoin(temp, path);
		free(temp);
		chdir(new);
	}
	else if (ft_is_dir(arg[1]) == 1)
		chdir(arg[1]);
	clean_cd(new, old, env);
}

void	clean_cd(char *new, char *old, char **env)
{
	if (new)
		free(new);
	ft_setenv(env, "OLDPWD", old);
	free(old);
	old = NULL;
	old = getcwd(old, 1024);
	ft_setenv(env, "PWD", old);
	free(old);
	old = NULL;
}