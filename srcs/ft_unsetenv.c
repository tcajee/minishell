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
	char *tmp;
	char **tab;
	char *ret;

	tmp = ft_strstr(path, "$");
	tab = ft_strsplit(tmp, '/');
	tmp = ft_strdup(tab[0]);
	ft_tabfree(tab);
	ret = ft_strstr(tmp, &tmp[1]);
	return ret;
}

char	*ft_getvar(char *path, char **env)
{
	char *var;
	int i;
	size_t len;
	char *ret;
	
	var = ft_find_variable(path);
	i = 0;
	len = ft_strlen(var);
	while (env[i])
	{
		if (ft_strncmp(env[i], var, len) == 0)
		{	
			ret = ft_strstr(env[i], "=");
			var = ft_strstr(ret, &ret[1]);
			return(var);
		}
		i++;
	}
	return NULL;
}

char	**ft_substitute(char *path, char **env)
{
	int i;
	char *var;
	char *value;
	char **tab;


	i = 0;
	var = ft_strjoin("$", ft_find_variable(path));
	value = ft_getvar(path, env);
	tab = ft_strsplit(path, '/');
	while (tab[i])
	{
		if (ft_strcmp(tab[i], var) == 0){
			ft_strdel(&tab[i]);
			tab[i] = ft_strdup(value);	
		}
		i++;
	}
	return tab;
}

char  *handler(char *path, char **env)
{

	return(ft_newpath(ft_substitute(path, env)));
}

char *ft_newpath(char **tab)
{
	int i;
	char *tmp;
	
	i = 0;
	tmp = "/";
	while(tab[i] != '\0')
	{	
		tmp = ft_strjoin(tmp, tab[i]);
		tmp = ft_strjoin(tmp, "/");
		i++;
	}
	return tmp;
}

