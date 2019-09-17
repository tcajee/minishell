/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaloyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:12:18 by mbaloyi           #+#    #+#             */
/*   Updated: 2018/09/13 11:16:29 by mbaloyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void	check_env_var(char *arg, char **env)
{
	int		i;
	char	**env_var;

	i = 0;
	while(env[i] != '\0')
	{
		env_var = ft_strsplit(env[i], '=');
		if (ft_strcmp(env_var[0], arg + 1) == 0)
			ft_printf("%s", env_var[1]);
		i++;
	}
}

void	do_env(char **env)
{
	int		i;

	i = 0;
	while (env[i] != '\0')
	{
		ft_printf("%s\n", env[i]);
	 	i++;
	}
}