/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:12:18 by mbaloyi           #+#    #+#             */
/*   Updated: 2019/09/19 12:30:50 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

void    echo_env(char *arg, char **env)
{
    int    i;
    char   **env_var;

    i = 0;
    while(env[i])
    {
        env_var = ft_strsplit(env[i++], '=');
        if (ft_strcmp(env_var[0], arg + 1) == 0)
        {
            ft_putstr(env_var[1]);
            free(env_var[0]);
            free(env_var[1]);
        }
    }
}

int   parse_echo(char *line)
{
    int     i;

    i = 4;
    if (!ft_strchr(line, '"') && !ft_strchr(line, '\''))
        return (0);
    while (line[i])
    {
        if (line[i] == '\'' && line[i + 1])
        {
            while (line[i + 1] && line[i + 1] != '\'')
            {
                ft_putchar(line[i + 1]);
                i++;
            }
        }
        else if (line[i] == '"' && line[i + 1])
        {
            while (line[i + 1] && line[i + 1] != '"')
            {
                ft_putchar(line[i + 1]);
                i++;
            }
        }
        i++;
    }
    ft_putstr("\n");
    return (1);
}

void    exec_echo(char **argv, char * line, char **env)
{
    int k;
    int i;

    /* (void)(line); */

    k = 1;
    i = 0;
    if (!argv[k])
        ft_putstr("\n");
    else if (!parse_echo(line))
    {
        while (argv[k])
        {
            if (argv[k][i] == '$')
                echo_env(argv[k], env);
            else
                ft_putstr(argv[k]);
            if (argv[++k])
                ft_putstr(" ");
        }
        ft_putstr("\n");
    }
}
