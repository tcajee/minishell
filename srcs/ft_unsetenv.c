/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_unsetenv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorac <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 11:03:34 by skorac            #+#    #+#             */
/*   Updated: 2019/09/19 12:30:09 by tcajee           ###   ########.fr       */
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
		ft_putendl("No variable entered");
		return (-1);
	}
	len = ft_strlen(elem);
	while (tab[i])
	{
		if (ft_strncmp(tab[i], elem, len) == 0)
		{
			ft_strdel(&tab[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_unsetenv(char **env, char *arg)
{
	int len;

	len = ft_tablen(env);
	if (ft_findremove(env, arg) == 0)
		ft_putendl("Variable not found");
	ft_pushback(env, &len);
}

char	*ft_find_variable(char *path)
{
		char **tab;
		char *tmp;
		int i;

		i = 0;
		tab = ft_tabdup(ft_strsplit(path, '/'));
		while (tab[i]){
			if (tab[i][0] == '$')
				tmp = ft_strdup(tab[i]);				
			i++;
		}
		ft_tabfree(tab);
		return(tmp);
}

char	*ft_getvar(char *path, char **env)
{
	char *var;
	int i;
	size_t len;
	char **tab;
	char *tmp;

	i = 0;
	tab = ft_tabdup(env);
	len = ft_strlen(var);	
	var = ft_strsub(ft_find_variable(path), 1, ft_strlen(var));
	while (tab[i])
	{
		if (ft_strncmp(tab[i], var, len) == 0)
			tmp = ft_strdup(tab[i]);
		i++;
	}
	free(tab);
	return(tmp);
}

char	*ft_replacevar(char *path, char **env)
{ 
	


}

