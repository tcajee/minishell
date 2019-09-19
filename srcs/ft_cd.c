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

static char *ft_home(char **env)
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

static char *ft_oldpwd(char **env)
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
	char	path[PATH_MAX];
	char *temp;
	char *old;

	old = NULL;
	old = getcwd(old, sizeof(old));
	temp = NULL;
	if (!arg[1] || (ft_strcmp(arg[1], "--") == 0) || (ft_strcmp(arg[1], "$HOME") == 0) || (ft_strcmp(arg[1], "~") == 0))
		chdir(temp = ft_home(env));
	else if ((ft_strcmp(arg[1], "-") == 0) || (ft_strcmp(arg[1], "$OLDPWD") == 0))
		chdir(temp = ft_oldpwd(env));
	else if (ft_is_dir(arg[1]) == 2)
	{
		readlink(arg[1], ft_memset(path, 0, PATH_MAX), PATH_MAX);
		temp = ft_strjoin(ft_strsub(arg[1], 0, (ft_strrchr(arg[1], '/') - arg[1] + 1 )), path);
		chdir(temp);
	}
	else if (ft_is_dir(arg[1]) == 1)
		chdir(arg[1]);

	ft_setenv(env, "OLDPWD", old);
	free(old);
	
	old = NULL;
	old = getcwd(old, sizeof(old));
	ft_setenv(env, "PWD", old);
	free(old);
	
	free(temp);
}
