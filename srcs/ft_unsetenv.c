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
	char *elem;

	elem = ft_strcat(arg, "=");
	len = ft_tablen(env);
	ft_findremove(env, arg);
	ft_pushback(env, &len);
	free(elem);
}