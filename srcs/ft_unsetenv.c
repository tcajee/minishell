/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorac <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 11:03:34 by skorac            #+#    #+#             */
/*   Updated: 2019/09/19 12:30:09 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int     remove_env(char **envv, char *elem)
{
    int i;
    int n;
    /* int len; */

    i = -1;
    if (!elem)
        return (-1);
    n = ft_strlen(elem);
    /* len = arr_len(envv); */
    while (envv[++i])
    {
        if (!ft_strncmp(envv[i], elem, n))
        {
            ft_strdel(&envv[i--]);
            while (envv[i++])
                envv[i] = envv[i + 1];
            envv[i] = NULL;
            break;
        }
    }
    return (0);
}

void    exec_unsetenv(char *arg, char **env)
{
    if (remove_env(env, arg) < 0)
        ft_putstr("\033[31m⮫ minishell: unsetenv: not enough args\033[0m\n");
    else if (!remove_env(env, arg))
    {
        ft_putstr("\033[31m⮫ minishell: unsetenv: ");
        ft_putstr(arg);
        ft_putstr(": variable not found\033[0m\n");
    }
}
