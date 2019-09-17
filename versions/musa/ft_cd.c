/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaloyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:12:18 by mbaloyi           #+#    #+#             */
/*   Updated: 2018/09/13 11:16:29 by mbaloyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static char *ft_home(char **env)
{
	char 	**home;
	int		i;

	i = 0;
	while(env[i] != NULL)
	{
		home = ft_strsplit(env[i], '=');
		if (ft_strcmp(home[0], "HOME") == 0)
			return(home[1]);
		i++;
	}
	return NULL;
}

static char *ft_oldpwd(char **env)
{
	char 	**home;
	int		i;

	i = 0;
	while(env[i] != NULL)
	{
		home = ft_strsplit(env[i], '=');
		if (ft_strcmp(home[0], "OLDPWD") == 0)
			return(home[1]);
		i++;
	}
	return NULL;
}

int			ft_is_dir(char *dir)
{
	struct stat		s_is;

	if (lstat(dir, &s_is) < 0)
	{
		ft_printf("cd: no such file or directory: %s\n", dir);
	}
	return (s_is.st_mode & S_IFDIR) ? 1 : 0;
}


void	do_cd(char **arg, char **env)
{
	char 	**cwd;
	char	**old;
	char	*path;
	char	*new_dir;
	char	*home;
	char	*oldpwd;

	cwd = (char **)malloc(sizeof(char *) * 3);
	old = (char **)malloc(sizeof(char *) * 3);
	new_dir = NULL;
	path = NULL;;
	home = NULL;
	oldpwd = NULL;
	old[0] = ft_strdup("setenv");
	old[1] = ft_strdup("OLDPWD");
	new_dir = getcwd(path, sizeof(new_dir));
	old[2] = ft_strdup(new_dir);
	home = ft_home(env);
	oldpwd = ft_oldpwd(env);
	
	new_dir = NULL;
	path = NULL;
	cwd[0] = ft_strdup("setenv");
	cwd[1] = ft_strdup("PWD");

	if (!arg[1] || (ft_strcmp(arg[1], "~") == 0) || 
		(ft_strcmp(arg[1], "--") == 0) || 
		(ft_strcmp(arg[1], "$HOME" ) == 0))
		chdir(home);
	else if ((ft_strcmp(arg[1], "-") == 0) || 
		(ft_strcmp(arg[1], "$OLDPWDcd " ) == 0))
		chdir(oldpwd);
	else if (ft_is_dir(arg[1]))
		chdir(arg[1]);
	else
		ft_printf("cd: no such file or directory: %s\n", arg[1]);
	do_setenv(old, &env);	
	new_dir = getcwd(path, sizeof(new_dir));
	cwd[2] = ft_strdup(new_dir);
	do_setenv(cwd, &env);
	free(new_dir);
	free(path);
}