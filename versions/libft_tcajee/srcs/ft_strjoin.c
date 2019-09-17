/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 11:34:12 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/20 09:43:10 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	len;

	new = NULL;
	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2) + 1;
		if (!(new = (char *)malloc(sizeof(char) * len)))
			return (NULL);
		new = ft_strcat(ft_strcpy(new, s1), s2);
		new[len] = '\0';
	}
	return (new);
}
