/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaloyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:12:18 by mbaloyi           #+#    #+#             */
/*   Updated: 2019/09/19 16:03:31 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

void    exec_putenv(char **env)
{
    int i;

    i = 0;
    while (env[i])
    {
        ft_putstr(env[i++]);
        ft_putstr("\n");
    }
}

void     replace_env(char **envv, char *key, char *value, int index)
{
    char    *temp;

    temp = ft_strjoin(key, "=");
    ft_strdel(&envv[index]);
    envv[index] = ft_strjoin(temp, value);
    (temp) ? free(temp) : NULL;
}

char    **add_env(char **envv, char *key, char *value, int len)
{
    int    i;
    char   *temp;
    char   **new;

    i = -1;
    new = (char **)malloc(sizeof(char *) * (arr_len(envv) + 2));
    while (envv[++i] && i < len)
    {
        new[i] = ft_strdup(envv[i]);
        free(envv[i]);
    }
    temp = ft_strjoin(key, "=");
    new[i++] = ft_strjoin(temp, value);
    new[i] = NULL;
    (temp) ? free(temp) : NULL;
    free(envv);
    return(new);
}

void    exec_setenv(char *key, char *value, char **envv)
{
    int i;
    int len;
    char **temp;

    i = -1;
    len = arr_len(envv);
    if (!key)
         ft_putstr("\033[31m⮫ minishell: setenv: not enough args\033[0m\n");
    else if (key)
    {
        ft_putstr("here");
        if (ft_strchr(key, '='))
        {
            temp = ft_strsplit(key, '=');
            key = temp[0];
            value = temp[1];
        }
        while (envv[++i])
        {
            if (!ft_strncmp(envv[i], key, ft_strlen(key)))
                return(replace_env(envv, key, value, i));
        }
        envv = add_env(envv, key, value, len);
        (temp) ? arr_del(temp) : NULL;
    }
}
