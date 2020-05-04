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

char     **remove_env(char ***envv, int index)
{
    int     i;
    int     j;
    int     len;
    char    **temp;
    char    **new;

    i = -1;
    j = -1;
    temp = *envv;
    len = arr_len(temp) - 1;
    new = (char**)malloc(sizeof(char *) * (len + 1));
    while (++j < len)
    {
        if (j == index)
            continue;
        new[++i] = ft_strdup(temp[j]);
    }
    arr_del(temp);
    new[i] = NULL;
    return (new);
}

void    exec_unsetenv(char *arg, char ***envv)
{
    int i;
    int     len;
    char    **temp;

    i = -1;
    temp = *envv;
    if (!arg)
        ft_putstr("\033[31m⮫ minishell: unsetenv: not enough args\033[0m\n");
    else
    {
        len = ft_strlen(arg);
        while (temp[++i])
        {
            if (!ft_strncmp(temp[i], arg, len))
                break;
        }
        if (!temp[i])
        {
            ft_putstr("\033[31m⮫ minishell: unsetenv: ");
            ft_putstr(arg);
            ft_putstr(": variable not found\033[0m\n");
        }
        else
            *envv = remove_env(envv, i);
    }
}
