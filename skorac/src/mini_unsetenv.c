/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_unsetenv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorac <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 11:03:34 by skorac            #+#    #+#             */
/*   Updated: 2018/09/27 13:51:21 by skorac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_findremove(char **tab, char *elem)
{
	int i;
	size_t len;

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
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_unsetenv(char **tab, char *elem)
{
	int len;

	len = ft_tablen(tab);
	ft_findremove(tab, elem);
	ft_pushback(tab, &len);
}
