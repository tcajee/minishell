/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorac <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 08:55:43 by skorac            #+#    #+#             */
/*   Updated: 2018/09/27 11:23:51 by skorac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int     ft_tablen(char **tab)
{
    int len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
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

//int		main()
//{
//	char **ret = ft_strsplit("hello*how*are*you", '*');
	
//	ft_tabsearch(ret, "hello");
//	return (0);

//}
