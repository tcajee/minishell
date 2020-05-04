/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:12:18 by mbaloyi           #+#    #+#             */
/*   Updated: 2019/09/19 12:28:41 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int     check_cd(char *dir)
{
    struct stat s;

    if (lstat(dir, &s) < 0)
    {
        ft_putstr("\033[31m⮫ cd: no such file or directory: ");
        (dir) ? ft_putstr(dir) : NULL;
        ft_putstr("\033[0m\n");
    }
    else if ((s.st_mode & S_IFMT) == S_IFLNK)
        return (2);
    else if ((s.st_mode & S_IFMT) == S_IFDIR)
    {
        if ((!(s.st_mode & S_IRGRP)
            && !(s.st_mode & S_IRUSR) && !(s.st_mode & S_IROTH)))
        {
            ft_putstr("\033[31m⮫ minishell: cd: ");
            (dir) ? ft_putstr(dir) : NULL;
            ft_putstr(": Permission denied\033[0m\n");
            return (0);
        }
        return (1);
    }
    return (0);
}

void     parse_cd(char *path, char **envv)
{
    char    *temp;

    temp = NULL;
    temp = getcwd(temp, 1024);
    exec_setenv("OLDPWD", temp, &envv);
    (temp) ? free(temp) : NULL;
    chdir(path);
    (path) ? free(path) : NULL;
    temp = NULL;
    temp = getcwd(temp, 1024);
    exec_setenv("PWD", temp, &envv);
    (temp) ? free(temp) : NULL;
}

void     exec_cd(char **argv, char **envv)
{
    char    *temp;
    char    *path;
    char    link[PATH_MAX];

    path = NULL;
    if (argv[2])
        ft_putstr("\033[31m⮫ minishell: cd: too many arguments\033[0m\n");
    else if (!argv[1] || (ft_strcmp(argv[1], "--") == 0))
        path = parse_vars(ft_strnew(0), "HOME", envv);
    else if (ft_strcmp(argv[1], "-") == 0)
        path = parse_vars(ft_strnew(0), "OLDPWD", envv);
    else if (!check_cd(argv[1]))
        return;
    else if (check_cd(argv[1]) == 2)
    {
        readlink(argv[1], ft_memset(link, 0, PATH_MAX), PATH_MAX);
        temp = ft_strsub(argv[1], 0, (ft_strrchr(argv[1], '/') - argv[1] + 1 ));
        path = ft_strjoin(temp, link);
        (temp) ? free(temp) : NULL;
    }
    else if (check_cd(argv[1]) == 1)
        path = ft_strdup(argv[1]);
    (!argv[2]) ? parse_cd(path, envv) : NULL;
}
