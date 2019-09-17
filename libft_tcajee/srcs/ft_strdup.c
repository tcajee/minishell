/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 08:10:57 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/20 09:43:10 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*new;

	new = NULL;
	len = 0;
	len = ft_strlen(s1);
	if (!(new = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	new[len] = '\0';
	return (ft_memcpy(new, s1, len));
}
