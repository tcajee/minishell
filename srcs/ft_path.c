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

int exec_path(char **temp, char *path, char **args, char **env)
{
    pid_t   pid;

    pid = fork();
    if (!pid)
        execve(path, args, env);
    else if (pid < 0)
    {
        ft_putstr("\033[31m⮫ minishell: execve: failed to fork!\033[0m\n");
        (path) ? free(path) : NULL;
        return (-1);
    }
    wait(&pid);
    (path) ? free(path) : NULL;
    (temp) ? arr_del(temp) : NULL;
    return (1);
}

int check_path(char *path, struct stat s_stat)
{
    if (s_stat.st_mode & S_IFREG)
    {
        if (s_stat.st_mode & S_IXUSR)
            return (1);
        else
        {
            ft_putstr("\033[31m⮫ minishell");
            ft_putstr(": Permission denied: ");
            ft_putstr(path);
            ft_putstr("\033[0m\n");
            return (-1);
        }
    }
    return (0);
}

int find_path(char **argv, char **env, char **path)
{
    char    *bin;
    char    *temp;
    int      status;
    int       i;
    struct stat s_stat;

    i = -1;
    bin = NULL;
    while (path && path[++i])
    {
        if (!(ft_strncmp(argv[0], path[i], ft_strlen(path[i]))))
            bin = ft_strdup(argv[0]);
        else
        {
            temp = ft_strjoin(path[i], "/");
            bin = ft_strjoin(temp, argv[0]);
            (temp) ? free(temp) : NULL;
        }
        if (lstat(bin, &s_stat) == -1 || !(status = check_path(bin, s_stat)))
            (bin) ? free(bin) : NULL;
        else if (status != -1)
            return(exec_path(path, bin, argv, env));
    }
    (path) ? arr_del(path) : NULL;
    return(0);
}

int	get_path(char **argv, char **env)
{
    int     i;
    char    **path;

    i = -1;
    path = NULL;
    if (str_isempty(argv[0]))
        return(1);
    while (env[++i])
    {
        if (!(ft_strncmp(env[i], "PATH", 4)))
            path = ft_strsplit(ft_strchr(env[i], '=') + 1, ':');
    }
    if (!path && (!ft_strncmp(argv[0], "/bin", 4) || !ft_strncmp(argv[0], "/usr/bin", 8)))
        path = ft_strsplit("/bin:/usr/bin", ':');
    return (find_path(argv, env, path));
}

int	str_isempty(char *check)
{
    int     i;

    i = 0;
    while (check && check[i])
    {
        if (!ft_isspace(check[i]))
            break;
        if (!check[++i])
            return(1);
    }
    return(0);
}
