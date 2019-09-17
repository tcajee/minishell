/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaloyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:12:18 by mbaloyi           #+#    #+#             */
/*   Updated: 2019/09/17 17:45:54 by tcajee           ###   ########.fr       */
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
