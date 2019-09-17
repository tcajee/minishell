/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 10:53:05 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/20 09:43:10 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t n)
{
	char	*new;
	size_t	i;

	new = NULL;
	if (s)
	{
		i = -1;
		if (!(new = (char *)malloc(sizeof(char) * n + 1)))
			return (NULL);
		while (++i < n && s[i])
			new[i] = s[start + i];
		new[i] = '\0';
	}
	return (new);
}
