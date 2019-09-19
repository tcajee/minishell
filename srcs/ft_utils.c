/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaloyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:12:18 by mbaloyi           #+#    #+#             */
/*   Updated: 2019/09/19 15:22:32 by enradcli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

int		ft_tabsearch(char **tab, char *elem)
{
	int i;
	char *tmp;

	i = 0;
	if (!elem)
		return (0);
	if (!tab)
		return (-1);
	tmp = ft_strjoin(elem, "=");
	while (tab[i])
	{
		if (ft_strncmp(tab[i], elem, ft_strlen(elem)) == 0)
		{
			free(tmp);
			return (i);
		}
		i++;
	}
	free(tmp);
	return (0);
}

char    **ft_tabdup(char **tab)
{
	int     i;
	int     len;
	char    **cpy;

	if (tab)
	{
		i = 0;
		len = ft_tablen(tab);
		if (!(cpy = (char**)malloc(sizeof(char *) * (len + 1))))
			return (NULL);
		while (i < len)
		{
			cpy[i] = ft_strdup(tab[i]);
			i++;
		}
		cpy[i] = NULL;
		return (cpy);
	}
	return (NULL);
}


int     ft_tablen(char **tab)
{
	int len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
}

void	ft_tabfree(char **tab)
{
	int len;
	int i;

	if (tab)
	{
		i = 0;
		len = ft_tablen(tab);
		while (i <= len)
		{
			free(tab[i]);
			i++;
		}
	}
}
