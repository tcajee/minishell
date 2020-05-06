/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 15:57:56 by tcajee            #+#    #+#             */
/*   Updated: 2020/05/04 01:44:52 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

void    exec_putenv(char **env)
{
    int i;

    i = 0;
    while (env[i])
        ft_putendl(env[i++]);
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
  char    *str;
  char    *str2;
  char    **new;
  char    **temp;

  i = -1;
  temp = *envv;
  new = (char **)malloc(sizeof(char *) * (len + 3));
  while (++i < len)
      new[i] = (char *)malloc(sizeof(char) * (ft_strlen(temp[i]) + 1));
  i = -1;
  while (temp[++i])
    new[i] = ft_strcpy(new[i], temp[i]);
  new[i] = (value)
      ? (char *)malloc(sizeof(char) * (ft_strlen(key) + ft_strlen(value) + 2))
      : (char *)malloc(sizeof(char) * (ft_strlen(key) + 2));
  str = ft_strjoin(key, "=");
  str2 = ft_strjoin(str, value);
  new[i] = (value) ? ft_strcpy(new[i], str2) : ft_strcpy(new[i], str) ;
  new[i + 1] = NULL;
  (str) ? ft_strdel(&str) : NULL;
  (str2) ? ft_strdel(&str2) : NULL;
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
