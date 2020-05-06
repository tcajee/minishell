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

int exec_path(char *bin, char **args, char **envv)
{
    pid_t   pid;

    if (!(pid = fork()))
        execve(bin, args, envv);
    else if (pid < 0)
    {
        ft_putstr("\033[31m⮫ minishell: execve: failed to fork!\033[0m\n");
        (bin) ? free(bin) : NULL;
        return (-1);
    }
    wait(&pid);
    (bin) ? free(bin) : NULL;
    return (1);
}

int check_path(char *bin)
{
    struct stat    s_stat;

    if (lstat(bin, &s_stat) == -1)
    {
        (bin) ? free(bin) : NULL;
        return (0);
    }
    if (s_stat.st_mode & S_IFREG)
    {
        if (s_stat.st_mode & S_IXUSR)
            return (1);
        else
        {
            ft_putstr("\033[31m⮫ minishell");
            ft_putstr(": Permission denied: ");
            (bin) ? ft_putstr(bin) : ft_putstr("");
            ft_putstr("\033[0m\n");
            (bin) ? free(bin) : NULL;
            return (0);
        }
    }
    (bin) ? free(bin) : NULL;
    return (0);
}


char *create_path(char *path, char *bin)
{
    int      i;
    int      j;
    char    *new;

    new = (char *)malloc(sizeof(char) * (ft_strlen(path) + ft_strlen(bin) + 1));
    ft_bzero(new, 0);
    i = 0;
    j = 0;
    while (path[i])
        new[j++] = path[i++];
    new[j++] = '/';
    i = 0;
    while (bin[i])
        new[j++] = bin[i++];
    new[j] = '\0';
    return(new);
}

int	get_path(char **argv, char **envv)
{
    int            i;
    int            status;
    char           *bin;
    char           **path;

    i = -1;
    if (str_isempty(argv[0]))
        return(1);
    path = NULL;
    while (envv[++i] && !path)
    {
        if (!(ft_strncmp(envv[i], "PATH", 4)))
            path = ft_strsplit(ft_strchr(envv[i], '=') + 1, ':');
    }
    if (!path && (!ft_strncmp(argv[0], "/bin", 4) || !ft_strncmp(argv[0], "/usr/bin", 8)))
        path = ft_strsplit("/bin:/usr/bin", ':');
    i = -1;
    while (path && path[++i])
    {
        bin = (!(ft_strncmp(argv[0], path[i], ft_strlen(path[i]))))
            ? ft_strdup(argv[0])
            : create_path(path[i], argv[0]);

        /* ft_putendl("\033[31m- get_path:"); */
        /* ft_putstr("argv[0]	["); */
        /* ft_putstr(argv[0]); */
        /* ft_putendl("]"); */
        /* ft_putstr("path[i]	["); */
        /* ft_putstr(path[i]); */
        /* ft_putendl("]"); */
        /* ft_putstr("bin	["); */
        /* ft_putstr(bin); */
        /* ft_putendl("]"); */
        /* ft_putstr("\033[0m\n"); */

        status = check_path(ft_strdup(bin));
        if (!status || status == -1)
        {
            /* (bin) ? free(bin) : NULL; */
            continue;
        }
        else
        {
            (path) ? arr_del(path) : NULL;
            return(exec_path(bin, argv, envv));
        }
    }
    (path) ? arr_del(path) : NULL;
    return(0);
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
