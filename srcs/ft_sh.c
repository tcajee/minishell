/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 12:52:36 by tcajee            #+#    #+#             */
/*   Updated: 2020/04/27 12:52:36 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

void    exec_line(char *line, char ***envv)
{
    char    **argv;

    line = strip_newline(line);
    argv = ft_strsplit(line, ' ');
    if (!argv || !argv[0] || !argv[0][0] || argv[0][0] == '\n')
        return;
    else if (ft_strcmp(argv[0], "cd") == 0)
        exec_cd(argv, *envv);
    else if ((ft_strcmp(argv[0], "echo") == 0))
        exec_echo(argv, line, *envv);
    else if (ft_strcmp(argv[0], "setenv") == 0 && argv[1])
        exec_setenv(argv[1], argv[2], *envv);
    else if (ft_strcmp(argv[0], "env") == 0)
        exec_putenv(*envv);
    else if (ft_strcmp(argv[0], "unsetenv") == 0)
        exec_unsetenv(argv[1], *envv);
    else if (ft_strcmp(argv[0], "exit") == 0)
        exec_exit(argv, *envv);
    else if (!(get_path(argv, *envv)))
    {
        ft_putstr("\033[31mminishell: ");
        ft_putstr(argv[0]);
        ft_putstr(" : command not found \033[0m\n");
    }
    arr_del(argv);
}

void exec_exit(char **argv, char **envv)
{
    (argv) ? arr_del(argv) : NULL;
    (envv) ? arr_del(envv) : NULL;
    exit(0);
}

int main(int argc, char **argv, char **env)
{
    char    *line;
    char    **envv;

    (void)(argc && argv);
    envv = arr_dup(env);
    ft_putstr("\n\033[0m\033[32m❯ Welcome to minishell!\033[0m\n");
    ft_putstr("\033[0m❯ ");
    while (get_next_line(0, &line) == 1)
    {
        if (ft_strchr(line, '$') || ft_strchr(line, '~'))
            line = parse_line(line, envv);
        exec_line(line, &envv);
        ft_putstr("❯ ");
    }
    return (0);
}
