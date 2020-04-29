/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 15:57:56 by tcajee            #+#    #+#             */
/*   Updated: 2020/04/27 15:58:52 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int exec_path(char *path, char **args, char **env)
{
    pid_t   pid;

    pid = fork();
    if (!pid)
        execve(path, args, env);
    else if (pid < 0)
    {
        ft_putstr("\033[31mminishell: execve: failed to fork!\033[0m\n");
        (path) ? free(path) : NULL;
        return (-1);
    }
    wait(&pid);
    (path) ? free(path) : NULL;
    return (1);
}

int check_path(char *path)
{
    struct stat s_stat;

    if (lstat(path, &s_stat) == -1)
        return (0);
    else
    {
        if (s_stat.st_mode & S_IFREG)
        {
            if (s_stat.st_mode & S_IXUSR)
                return (1);
            else
            {
                ft_putstr("\033[31mminishell");
                ft_putstr(": Permission denied: ");
                ft_putstr(path);
                ft_putstr("\033[0m\n");
                return (-1);
            }
        }
        return (0);
    }
}

int find_path(char **argv, char **env, char **path)
{
    char    *bin;
    char    *temp;
    int     status;
    int     i;

    i = -1;
    while (path && path[++i])
    {
        if (!(ft_strncmp(argv[0], path[i], ft_strlen(path[i]))))
            bin = ft_strdup(argv[0]);
        else
        {
            temp = ft_strjoin(path[i], "/");
            bin = ft_strjoin(temp, argv[0]);
        }
        if (!(status = check_path(bin)))
            free(bin);
        else if (status != -1)
            return(exec_path(bin, argv, env));
    }
    arr_del(path);
    return(0);
}

int get_path(char **argv, char **env)
{
    int     i;
    char    **path;

    i = -1;
    path = NULL;
    while (env[++i])
    {
        if (!(ft_strncmp(env[i], "PATH", 4)))
            path = ft_strsplit(ft_strchr(env[i], '=') + 1, ':');
    }
    return (find_path(argv, env, path));
}
