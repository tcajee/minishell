/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaloyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:12:18 by mbaloyi           #+#    #+#             */
/*   Updated: 2019/09/19 12:29:55 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

void	ft_putenv(char **env)
{
	int i;

	i = 0;
	while (env[i])
		ft_printf("%s\n", env[i++]);
}

int		ft_findreplace(char **tab, char *elem, char *data)
{
	int i;
	size_t len;
	char	*tmp;
	char	*ret;

	i = 0;
	if (!elem)
	{
		ft_printf("No variable entered\n");
		return (-1);
	}
	len = ft_strlen(elem);
	while (tab[i])
	{
		if (ft_strncmp(tab[i], elem, len) == 0)
		{
			ft_strdel(&tab[i]);
			tmp = ft_strjoin(elem, "=");
			ret = ft_strjoin(tmp, data);
			tab[i] = ft_strdup(ret);
			free(tmp);
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_pushback(char **tab, int *len)
{
	int i;
	char *tmp;

	i = 0;
	*len -= 1;
	while (i < *len)
	{
		if (tab[i] == NULL && tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
		}
		i++;
	}
}
void	ft_newenv(char **tab, char *elem, char *data)
{	
	int len;
	char *tmp;
	char *ret;

	tmp = ft_strcat(elem, "=");
	len = ft_tablen(tab);
	if (tab[len] == NULL)
	{
		ret = ft_strcat(tmp, data);
		tab[len] = ft_strdup(ret);  
		tab[len + 1] = NULL;
	}
}
void	ft_setenv(char **tab, char *elem, char *data)
{
	int len;

	len = ft_tablen(tab);
	if (ft_findreplace(tab, elem, data) == 0)
	{
		ft_newenv(tab, elem, data);
	}
	/* ft_pushback(tab, &len); */
	ft_pushback(tab, &len);
}
