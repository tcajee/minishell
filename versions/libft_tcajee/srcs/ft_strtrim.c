/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 16:03:32 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/20 09:43:10 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

char	*ft_strtrim(char const *s)
{
	const char	*start;
	const char	*end;
	char		*new;
	size_t		len;

	new = NULL;
	if (s)
	{
		len = 0;
		end = (s + (ft_strlen(s)));
		while (ft_isspace(*s) && *s)
			s++;
		start = s;
		while (ft_isspace(*(end - 1)) && end != s)
			end--;
		while (s++ != end)
			len++;
		if (!(new = ft_strsub(start, 0, len)))
			return (NULL);
	}
	return (new);
}
