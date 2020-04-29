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

int     replace_env(char **envv, char *elem, char *data)
{
    int     i;
    size_t  len;
    char    *ret;
    char    *temp;

    i = 0;
    if (!elem)
    {
        ft_putstr("\033[31mNo variable data entered\033[0m\n");
        return (-1);
    }
    len = ft_strlen(elem);
    while (envv[i])
    {
        if (!ft_strncmp(envv[i], elem, len))
        {
            ft_strdel(&envv[i]);
            temp = ft_strjoin(elem, "=");
            ret = ft_strjoin(temp, data);
            (temp) ? free(temp) : NULL;
            envv[i] = ft_strdup(ret);
            (ret) ? free(ret) : NULL;
            return (1);
        }
        i++;
    }
    return (0);
}

void    add_env(char **envv, char *elem, char *data)
{
     int    len;
     char   *temp;
     char   *ret;

     len = arr_len(envv);
     temp = ft_strcat(elem, "=");
     if (!data)
          ft_putstr("\033[31mNo variable data entered\033[0m\n");
     else if (!envv[len])
     {
         ret = ft_strcat(temp, data);
         (temp) ? free(temp) : NULL;
         envv[len] = ft_strdup(ret);
         (ret) ? free(ret) : NULL;
         envv[len + 1] = NULL;
     }
}

void    exec_setenv(char *key, char *value, char **envv)
{
    char **temp;

    temp = NULL;
    if (!value && key)
    {
        temp = ft_strsplit(key, '=');
        if (temp)
        {
            if (replace_env(envv, temp[0], temp[1]) == 0)
            {
                add_env(envv, temp[0], temp[1]);
                (temp[0]) ? free(temp[0]) : NULL;
                (temp[1]) ? free(temp[1]) : NULL;
            }
        }
    }
    else if (value && key)
    {
        if (replace_env(envv, key, value) == 0)
            add_env(envv, key, value);
    }
    (temp) ? free(temp) : NULL;
}
