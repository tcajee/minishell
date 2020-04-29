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

void    push_env(char **envv, int *len)
{
    int     i;
    char    *temp;

    i = -1;
    *len -= 1;
    while (i < *len)
    {
        if (!envv[i] && envv[i + 1])
        {
            temp = envv[i];
            envv[i] = envv[i + 1];
            envv[i + 1] = temp;
        }
        i++;
    }
}

int     remove_env(char **tab, char *elem)
{
    int i;
    size_t len;

    i = 0;
    if (!elem)
    {
        ft_putstr("\033[31mminishell: unsetenv: no variable entered\033[0m\n");
        return (-1);
    }
    len = ft_strlen(elem);
    while (tab[i])
    {
        if (ft_strncmp(tab[i], elem, len) == 0)
        {
            ft_strdel(&tab[i]);
            return (1);
        }
        i++;
    }
    return (0);
}

void    exec_unsetenv(char *arg, char **env)
{
    int len;

    len = arr_len(env);
    if (remove_env(env, arg) == 0)
    {
        ft_putstr("\033[31mminishell: unsetenv: ");
        ft_putstr(arg);
        ft_putstr(" : variable not found\033[0m\n");
    }
    push_env(env, &len);
}
