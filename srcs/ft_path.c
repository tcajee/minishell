/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                           :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:12:18 by tcajee            #+#    #+#             */
/*   Updated: 2019/09/19 18:07:55 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

int	exec_path(char *path, char **args, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		execve(path, args, env);
	else if (pid < 0)
	{
		ft_putendl("Forking failed!");
		free(path);
		return (-1);
	}
	wait(&pid);
	if (path)
		free(path);
	return (1);
}

int check_bin(char *bin)
{
	struct stat	s_stat;

	if (lstat(bin, &s_stat) == -1)
		return (0);
	else
	{
		if (s_stat.st_mode & S_IFREG)
		{
			if (s_stat.st_mode & S_IXUSR)
				return (1);
			else
			{
				ft_putstr("minishell: permission denied: ");
				ft_putendl(bin);
				return (-1);
			}
		}
		return (0);
	}
}

int find_path(char **argv, char **env, char **path)
{
	char	*bin;
	char	*temp;
	int		i;
	int		status;
	
	i = -1;
	while (path[++i])
	{
		if (!(ft_strncmp(argv[0], path[i], ft_strlen(path[i]))))
			bin = ft_strdup(argv[0]);
		else
		{
			temp = ft_strjoin(path[i], "/");
			bin = ft_strjoin(temp, argv[0]);
		}
		if (!(status = check_bin(bin)))
			free(bin);
		else if (status != -1)
			return(exec_path(bin, argv, env));
	}
	ft_tabfree(path);
	return(0);
}

int		get_path(char **argv, char **env)
{
	int				i;
	char			**path;

	i = -1;	
	path = NULL;
	while (env[++i])
	{
		if (!(ft_strncmp(env[i], "PATH", 4)))
			path = ft_strsplit(ft_strchr(env[i], '=') + 1, ':');
	}
	return (find_path(argv, env, path));
}