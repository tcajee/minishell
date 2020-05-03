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
    envv[index] = (value) ? ft_strjoin(temp, value) : temp;
    (value) ? free(temp) : NULL;
}

char    **add_env(char ***envv, char *key, char *value, int len)
{
  int     i;
  char    **temp;
  char    **new;

  i = -1;
  temp = *envv;
  new = (char **)malloc(sizeof(char *) * (len + 3));
  while (++i < len)
      new[i] = (char *)malloc(sizeof(char) * (ft_strlen(temp[i]) + 1));
  i = -1;
  while (temp[++i])
    new[i] = ft_strcpy(new[i], temp[i]);
  new[i] = (char *)malloc(sizeof(char) * (ft_strlen(key) + ft_strlen(value) + 2));
  new[i] = ft_strcpy(new[i], key);
  new[i] = ft_strcat(new[i], "=");
  new[i] = ft_strcat(new[i], value);
  new[i + 1] = NULL;
  (temp) ? arr_del(temp) : NULL;
  return(new);
}

int    check_env(char **envv, char *key, char *value)
{
    int   i;

    i = -1;
    while (envv[++i])
    {
        if (!strncmp(envv[i], key, ft_strlen(key)))
        {
            replace_env(envv, key, value, i);
            return(1);
        }
    }
    return(0);
}

void    exec_setenv(char *key, char *value, char ***envv)
{
    int     len;
    char    **temp;

    temp = NULL;
    len = arr_len(*envv);
    if (!key)
         ft_putstr("\033[31m⮫ minishell: setenv: not enough args\033[0m\n");
    else if (key)
    {
        if (!value)
        {
            temp = ft_strsplit(key, '=');
            if (temp)
            {
                key = temp[0];
                value = temp[1];
            }
        }
        if (!check_env(*envv, key, value))
            *envv = add_env(envv, key, value, len);
        (temp) ? arr_del(temp) : NULL;
    }
}
