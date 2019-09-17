/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaloyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:12:18 by mbaloyi           #+#    #+#             */
/*   Updated: 2018/09/13 11:16:29 by mbaloyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int		ft_strlen_double(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return(i);
	free(str);
}

void	ft_input(void)
{
	char	*path;
	char	**pathreal;
	int		last;

	path = NULL;
	last = 0;
	pathreal = NULL;
	path = getcwd(path, sizeof(path));
	if (ft_strcmp(path, "/") == 0)
		 ft_printf("%s[ %s ]%s%s[$➜] %s", GREEN, 
		path, RESET, RED, RESET);
	else
	{
		pathreal = ft_strsplit(path, '/');
		last = ft_strlen_double(pathreal);
		ft_printf("%s[ %s ]%s%s[$➜] %s", GREEN, 
		pathreal[last - 1], RESET, RED, RESET);
	}
	free(path);
	free(pathreal);
}

char	**ft_strcpy_double(char **arr)
{
	int		k;
	int		i;
	char	**big;

	k = ft_strlen_double(arr);
	i = 0;
	if (!(big = (char **)malloc(sizeof(char *) * (k + 1))))
		return (NULL);
	big[k + 1] = NULL;
	while (i != k)
	{
		big[i] = ft_strnew(ft_strlen(arr[i]));
		ft_strcpy(big[i], arr[i]);
		i++;
	}
	return (big);
}