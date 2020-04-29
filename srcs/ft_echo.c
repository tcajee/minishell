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

void    exec_echo(char **argv, char * line, char **env)
{
    int k;
    int i;

    (void)(line);

    k = 1;
    i = 0;
    if (!argv[k])
        ft_putstr("\n");
    while (argv[k])
    {
        if (argv[k][i] == '$')
            echo_env(argv[k], env);
        else
            /* parse_echo(argv[k]); */
            ft_putstr(argv[k]);
        if (argv[++k])
            ft_putstr(" ");
        ft_putstr("\n");
    }
}
