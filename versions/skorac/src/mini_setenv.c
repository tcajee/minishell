/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_setenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorac <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 12:31:10 by skorac            #+#    #+#             */
/*   Updated: 2018/09/27 13:52:04 by skorac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/minishell.h"

int     ft_findreplace(char **tab, char *elem, char *data)
{
    int i;
    size_t len;
	char	*tmp;
	char	*ret;
    i = 0;
    if (!elem)
    {
        printf("No variable entered\n");
        return (-1);
    }
    len = ft_strlen(elem);
    while (tab[i])
    {
        if (ft_strncmp(tab[i], elem, len) == 0 && elem[len + 1] == '=')
        {
            ft_strdel(&tab[i]);
            tmp = ft_strjoin(elem, "=");
			ret = ft_strjoin(tmp, data);
			tab[i] = ft_strdup(ret);
			return (1);
        }
        i++;
    }
    return (0);
}

void        ft_pushback(char **tab, int *len)
{
    int i;
    char *tmp;

    i = 0;
    *len -= 1;
    while (i < *len)
    {
        if (tab[i] == NULL  && tab[i + 1])
        {
            tmp = tab[i];
            tab[i] = tab[i + 1];
            tab[i + 1] = tmp;
        }
        i++;
    }
}

void    ft_setenv(char **tab, char *elem, char *data)
{
    int len;

    len = ft_tablen(tab);
    ft_findreplace(tab, elem, data);
    ft_pushback(tab, &len);
}
