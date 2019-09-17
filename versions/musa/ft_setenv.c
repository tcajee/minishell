/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaloyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:12:18 by mbaloyi           #+#    #+#             */
/*   Updated: 2018/09/13 11:16:29 by mbaloyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static char		**set_new_env(char **env, char **arg, int num_arg)
{
	char	**new;
	int		i;
	int		count;
	char	*arg_join;

	i = 0;
	count = ft_strlen_double(env);
	new = (char **)malloc(sizeof(char *) * count + 2);
	while (i != count)
	{
		new[i] = env[i];
		i++;
	}
	arg_join = ft_strcat(arg[1], "=");
	if (num_arg == 3)
		arg_join = ft_strcat(arg_join, arg[2]);
	new[i] = ft_strnew(ft_strlen(arg_join));
	new[i] = ft_strdup(arg_join);
	new[i + 1] = NULL;
	free(env);
	return (new);
}

void	do_setenv(char **arg, char ***env)
{
	char	**env_var;
	int		env_count;
	int		count;
	int		i;

	i = 0;
	count = 0;
	env_count = 0;
	while (arg[count] != NULL)
		count++;
	while ((*env)[env_count] != NULL)
		env_count++;
	if (count == 1)
	{
		do_env(*env);
		return ;
	}
	if (count > 3)
	{
		ft_printf("setenv: too many arguements\n");
	}
	if (count > 1 && count < 4)
	{
		while ((*env)[i] != NULL)
		{
			env_var = ft_strsplit((*env)[i], '=');
			if (ft_strcmp(arg[1], env_var[0]) == 0)
			{
				ft_strcat(env_var[0], "=");
				if (count == 3)
				{
					env_var[1] = NULL;
					env_var[1] = ft_strnew(ft_strlen(arg[2]));	
					ft_strcpy(env_var[1], arg[2]);
					(*env)[i] = ft_strcat(env_var[0], env_var[1]);
					break ;
				}
				(*env)[i] = env_var[0];
				break ;
			}
			free(env_var);
			env_var = NULL;
			i++;
		}
		if (i == env_count)
		{
			*env = set_new_env(*env, arg, count);
			return ;
		}
	}
}