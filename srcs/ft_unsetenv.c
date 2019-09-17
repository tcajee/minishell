/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_unsetenv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorac <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 11:03:34 by skorac            #+#    #+#             */
/*   Updated: 2019/09/17 17:50:57 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

int		ft_findremove(char **tab, char *elem)
{
	int i;
	size_t len;

	i = 0;
	if (!elem)
	{
		printf("No variable entered\n");
		/* ft_printf("No variable entered\n"); */
		return (-1);
	}
	len = ft_strlen(elem);
	while (tab[i])
	{
		if (ft_strncmp(tab[i], elem, len) == 0 && elem[len + 1] == '=')
		{
			ft_strdel(&tab[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

int     ft_tablen(char **tab)
{
	int len;
	len = 0;
	while (tab[len])
		len++;
	return (len);
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

void	ft_unsetenv(char **tab, char *elem)
{
	int len;

	len = ft_tablen(tab);
	ft_findremove(tab, elem);
	ft_pushback(tab, &len);
}
